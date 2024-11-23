#include "worker.h"

Worker::Worker(int number, int start, int stop)
{
    m_number = number;
    m_start = start;
    m_stop = stop;
}

void Worker::calculate()
{
    for (int iterator=m_start; iterator<m_stop; iterator++) {
        QThread::sleep(1);
        qDebug() << "Thread # " << m_number << ": " << iterator;
    }
}
