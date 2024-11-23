#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QDebug>
#include <QThread>

class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(int number = -1, int start = -1, int stop = -1);

public slots:
    void calculate();

signals:

private:
    int m_number;
    int m_start;
    int m_stop;
};

#endif // WORKER_H
