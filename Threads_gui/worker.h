#ifndef WORKER_H
#define WORKER_H

#include <QThread>
#include <QRandomGenerator>

class Worker : public QThread
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = nullptr);
protected:
    virtual void run();

signals:
    void value(int);
};

#endif // WORKER_H
