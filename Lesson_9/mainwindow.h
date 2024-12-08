#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>

#include "aiworker.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void ask();

signals:
    void askAi(QString text);

public slots:
    void updateAiAnswer(QString text);

private:
    Ui::MainWindow *ui;
    QThread *m_aiThread;
    AIWorker *m_aiWorker;
};
#endif // MAINWINDOW_H
