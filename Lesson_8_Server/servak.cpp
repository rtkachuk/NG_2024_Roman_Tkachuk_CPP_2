#include "servak.h"

Servak::Servak(QObject *parent)
    : QObject{parent}
{
    m_servak = new QTcpServer(this);

    connect (m_servak, &QTcpServer::newConnection, this, &Servak::newClient);
}

void Servak::start(int port, QHostAddress address)
{
    bool ok = m_servak->listen(address, port);
    if (ok) {
        emit started();
        log("Server started");
    } else {
        log ("Server fail");
    }
}

void Servak::newClient()
{
    QTcpSocket *socket = m_servak->nextPendingConnection();
    log("New client: " + socket->peerAddress().toString());

    connect (socket, &QTcpSocket::disconnected, this, &Servak::clientDisconnected);
    connect (socket, &QTcpSocket::readyRead, this, &Servak::newMessage);

    m_users[socket] = "Anonymous";
}

void Servak::clientDisconnected()
{
    QTcpSocket *socket = (QTcpSocket *)sender();

    log ("Client disconnected: " + socket->peerAddress().toString());

    disconnect (socket, &QTcpSocket::disconnected, this, &Servak::clientDisconnected);
    disconnect (socket, &QTcpSocket::readyRead, this, &Servak::newMessage);

    m_users.remove(socket);
}

void Servak::newMessage()
{
    QTcpSocket *socket = (QTcpSocket *)sender();
    QByteArray message =socket->readAll();
    if (message.indexOf(m_loginKey) == 0) {
        QByteArray login = message.remove(0, m_loginKey.size());
        m_users[socket] = login;
        log("User " +
            socket->peerAddress().toString() +
            " now known as " + QString(login));
    }
    else {
        for (QTcpSocket* client : m_users.keys()) {
            client->write("[ " + m_users[socket] + " ] : " + message);
            client->flush();
        }
    }
}

void Servak::log(QString message)
{
    qDebug() << "[Servak] " << QDateTime::currentDateTime().toString() << ": " << message;
}
