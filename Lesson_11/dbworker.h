#ifndef DBWORKER_H
#define DBWORKER_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlResult>
#include <QDebug>

struct User {
    int id;
    QString name;
    QString login;
    bool isAdmin;
};

class DbWorker : public QObject
{
    Q_OBJECT
public:
    explicit DbWorker(QObject *parent = nullptr);
    void initDb();

    bool createUser(QString name, QString login, QString password, bool isAdmin);
    User loginUser(QString login, QString password);
signals:

private:
    QSqlDatabase m_db;

    void log(QString message);
    bool checkAdminExist();
};

#endif // DBWORKER_H
