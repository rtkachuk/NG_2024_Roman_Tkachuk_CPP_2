#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_aiWorker = new AIWorker();
    m_aiThread = new QThread(this);
    m_aiThread->start();
    m_aiWorker->moveToThread(m_aiThread);

    ui->te_ai->setReadOnly(true);

    connect (ui->b_ask, &QPushButton::clicked, this, &MainWindow::ask);
    connect (this, &MainWindow::askAi, m_aiWorker, &AIWorker::askAI);
    connect (m_aiWorker, &AIWorker::answerReady, this, &MainWindow::updateAiAnswer);
    connect (m_aiWorker, &AIWorker::statusUpdate, ui->statusbar, &QStatusBar::showMessage);
}

MainWindow::~MainWindow()
{
    m_aiThread->exit(0);
    delete m_aiWorker;

    delete ui;
}

void MainWindow::ask()
{
    emit askAi(ui->te_user->toPlainText());
}

void MainWindow::updateAiAnswer(QString text)
{
    ui->te_ai->setText(text);
}
