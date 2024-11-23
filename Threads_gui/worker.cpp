#include "worker.h"

Worker::Worker(QObject *parent)
    : QThread{parent}
{}

void Worker::run()
{
    for (int index = 0; index <= 100; index++) {
        QThread::sleep(QRandomGenerator::global()->bounded(3));
        emit value(index);
    }
}
