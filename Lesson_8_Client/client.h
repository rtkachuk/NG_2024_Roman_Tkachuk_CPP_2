#ifndef CLIENT_H
#define CLIENT_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QThread>

QT_BEGIN_NAMESPACE
namespace Ui {
class Client;
}
QT_END_NAMESPACE

class Client : public QMainWindow
{
    Q_OBJECT

public:
    Client(QWidget *parent = nullptr);
    ~Client();

private slots:
    void joinChat();
    void joined();
    void kicked();
    void sendMessage();
    void gotMessage();

private:
    const QByteArray m_loginKey = "{{login}}";

    Ui::Client *ui;
    QTcpSocket *m_socket;
    QThread *m_thread;
};
#endif // CLIENT_H
