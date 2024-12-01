#ifndef SERVAK_H
#define SERVAK_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDateTime>
#include <QDebug>
#include <QMap>

class Servak : public QObject
{
    Q_OBJECT
public:
    explicit Servak(QObject *parent = nullptr);

public slots:
    void start(int port, QHostAddress address);

signals:
    void started();
    void stopped();

private slots:
    void newClient();
    void clientDisconnected();
    void newMessage();

private:
    void log(QString message);

    const QByteArray m_loginKey = "{{login}}";

    QTcpServer *m_servak;
    QMap<QTcpSocket*, QByteArray> m_users;
};

#endif // SERVAK_H
