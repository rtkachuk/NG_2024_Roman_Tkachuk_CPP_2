#include "aiworker.h"

AIWorker::AIWorker(QObject *parent)
    : QObject{parent}
{
    m_manager = new QNetworkAccessManager(this);

    connect (m_manager, &QNetworkAccessManager::finished, this, &AIWorker::receivedAnswer);
}

void AIWorker::receivedAnswer(QNetworkReply *reply)
{
    if (reply->error() == QNetworkReply::NoError) {
        emit answerReady(QJsonDocument::fromJson(reply->readAll()).object().value("response").toString());
        emit statusUpdate("Done!");
    } else {
        qDebug() << "Error: " << reply->errorString();
        emit statusUpdate(reply->errorString());
    }
}

void AIWorker::askAI(QString question)
{
    QNetworkRequest request(QUrl("http://127.0.0.1:11434/api/generate"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QJsonObject json;
    json["model"] = "llama3.2:latest";
    json["prompt"] = question;
    json["stream"] = false;

    QNetworkReply *reply = m_manager->post(request, QJsonDocument(json).toJson());
    emit statusUpdate("Thinking...");
}
