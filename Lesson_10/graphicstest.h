#ifndef GRAPHICSTEST_H
#define GRAPHICSTEST_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QDebug>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QJsonObject>
#include <QJsonDocument>
#include "aiworker.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class GraphicsTest;
}
QT_END_NAMESPACE

class GraphicsTest : public QMainWindow
{
    Q_OBJECT

public:
    GraphicsTest(QWidget *parent = nullptr);
    ~GraphicsTest();

protected:
    virtual void keyPressEvent(QKeyEvent *key);

private slots:
    void askAi();
    void aiAnswer(QString text);
    void updateStatus(QString text);

private:
    Ui::GraphicsTest *ui;
    QGraphicsScene *m_scene;
    QPixmap *m_playerIcon;
    QGraphicsPixmapItem *m_player;
    AIWorker *ai;

    const int pointSize = 50;
    const int screenHeight = 1080;
    const int screenWidth = 1920;

signals:
    void processToAi(QString text);

};
#endif // GRAPHICSTEST_H
