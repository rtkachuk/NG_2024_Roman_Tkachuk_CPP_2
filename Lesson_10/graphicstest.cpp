#include "graphicstest.h"
#include "ui_graphicstest.h"

GraphicsTest::GraphicsTest(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GraphicsTest)
{
    ui->setupUi(this);
    m_scene = new QGraphicsScene(this);
    ui->view->setScene(m_scene);
    m_scene->setSceneRect(0,0, screenWidth, screenHeight);

    m_playerIcon = new QPixmap("/home/rtkachuk/texture.png");

    for (int row = 0; row < screenHeight; row += pointSize) {
        m_scene->addLine(0, row, screenWidth, row);
    }

    for (int col = 0; col < screenWidth; col += pointSize) {
        m_scene->addLine(col, 0, col, screenHeight);
    }

    m_player = m_scene->addPixmap(*m_playerIcon);

    QRectF rectangle = m_scene->sceneRect();
    qDebug() << rectangle.topLeft().x() << ":::" << rectangle.topLeft().y();
    qDebug() << rectangle.bottomRight().x() << ":::" << rectangle.bottomRight().y();

    m_scene->update();

    // AI part, can be commented out if not required
    //

    ai = new AIWorker(this);

    connect (ui->b_go, &QPushButton::clicked, this, &GraphicsTest::askAi);
    connect (this, &GraphicsTest::processToAi, ai, &AIWorker::askAI);
    connect (ai, &AIWorker::answerReady, this, &GraphicsTest::aiAnswer);
    connect (ai, &AIWorker::statusUpdate, this, &GraphicsTest::updateStatus);
}

GraphicsTest::~GraphicsTest()
{
    delete ui;
}

void GraphicsTest::keyPressEvent(QKeyEvent *keyEvent)
{
    QPointF point = m_player->pos();
    switch (keyEvent->key()) {
    case Qt::Key_D: point.setX(point.x() + pointSize); break;
    case Qt::Key_A: point.setX(point.x() - pointSize); break;
    case Qt::Key_W: point.setY(point.y() - pointSize); break;
    case Qt::Key_S: point.setY(point.y() + pointSize); break;
    }
    m_player->setPos(point);
    m_scene->update();
}

void GraphicsTest::askAi()
{
    QString basePrompt = "You are a paint robot. You can draw only using lines. All you can answer should be x and y points, which will represent lines of a picture. Your top left point is 0,0. Your bottom right point is 1920,1080. Your answer should be in json array of objects x and y. Example answer: [ {\"x1\": 100, \"y1\":100, \"x2\":150, \"y2\":150} ]. Each object represent line. You can answer only in json format.";
    QString text = ui->pte_ask->toPlainText();
    emit processToAi(basePrompt + text);
}

void GraphicsTest::aiAnswer(QString text)
{
    qDebug() << text;
    ui->pte_ask->clear();
    m_scene->clear();
    m_scene->setSceneRect(0,0, screenWidth, screenHeight);
    QJsonArray array = QJsonDocument::fromJson(text.toUtf8()).array();
    while (array.isEmpty() == false) {
        QJsonObject object = array.first().toObject();
        array.pop_front();
        int x1 = object.value("x1").toInt();
        int y1 = object.value("y1").toInt();
        int x2 = object.value("x2").toInt();
        int y2 = object.value("y2").toInt();
        m_scene->addLine(x1,y1,x2,y2);
    }
    m_scene->update();
}

void GraphicsTest::updateStatus(QString text)
{
    ui->statusbar->showMessage(text);
}
