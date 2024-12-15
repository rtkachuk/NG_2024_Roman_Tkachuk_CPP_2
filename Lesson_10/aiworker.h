#ifndef AIWORKER_H
#define AIWORKER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QDebug>

class AIWorker : public QObject
{
    Q_OBJECT
public:
    explicit AIWorker(QObject *parent = nullptr);

private slots:
    void receivedAnswer(QNetworkReply *reply);

public slots:
    void askAI(QString question);

signals:
    void answerReady(QString text);
    void statusUpdate(QString text, int timeout = 0);

private:
    QNetworkAccessManager *m_manager;
};

#endif // AIWORKER_H
