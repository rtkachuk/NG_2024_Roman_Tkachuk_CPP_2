#include "lolthreads.h"
#include "ui_lolthreads.h"

LOLThreads::LOLThreads(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LOLThreads)
{
    ui->setupUi(this);

    connect (ui->b_start, &QPushButton::clicked, this, &LOLThreads::start);
}

LOLThreads::~LOLThreads()
{
    delete ui;
}

void LOLThreads::start()
{
    int threads = 4;
    int endNumber = 100;

    for (int i=0; i<threads; i++) {
        m_threads.append(new QThread());
        m_workers.append(new Worker(i + 1, endNumber / threads * i, endNumber / threads * (i+1)));
        m_workers[i]->moveToThread(m_threads[i]);
        m_threads[i]->start();

        connect (this, &LOLThreads::startJobs, m_workers[i], &Worker::calculate);

        //m_workers[i]->calculate(endNumber / threads * i, endNumber / threads * (i+1));
    }

    emit startJobs();
}
