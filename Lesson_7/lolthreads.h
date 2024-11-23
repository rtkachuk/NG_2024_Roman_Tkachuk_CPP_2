#ifndef LOLTHREADS_H
#define LOLTHREADS_H

#include <QMainWindow>
#include <QThread>

#include "worker.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class LOLThreads;
}
QT_END_NAMESPACE

class LOLThreads : public QMainWindow
{
    Q_OBJECT

public:
    LOLThreads(QWidget *parent = nullptr);
    ~LOLThreads();

private slots:
    void start();

signals:
    void startJobs();

private:
    Ui::LOLThreads *ui;
    QVector<Worker*> m_workers;
    QVector<QThread*> m_threads;
};
#endif // LOLTHREADS_H
