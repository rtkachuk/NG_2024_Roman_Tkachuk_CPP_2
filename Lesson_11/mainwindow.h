#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dbworker.h"

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
    void b_enter();
    void b_exit();
    void b_createUser();

private:
    Ui::MainWindow *ui;
    DbWorker *m_dbWorker;
    User m_user;
};
#endif // MAINWINDOW_H
