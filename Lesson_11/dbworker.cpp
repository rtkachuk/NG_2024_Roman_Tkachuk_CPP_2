#include "dbworker.h"

DbWorker::DbWorker(QObject *parent)
    : QObject{parent}
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("./users.db");
    if (m_db.open())
        log("Database connected!");
    else {
        log("Database connection error!");
        log(m_db.lastError().databaseText());
    }
}

void DbWorker::initDb()
{
    QSqlQuery query;
    QString sql;
    sql = "CREATE TABLE IF NOT EXISTS users(";
    sql += "id INTEGER PRIMARY KEY AUTOINCREMENT,";
    sql += "name TEXT,";
    sql += "login TEXT UNIQUE,";
    sql += "password TEXT,";
    sql += "isAdmin BOOLEAN);";
    if (query.exec(sql)) {
        log ("Successfully executed CREATE TABLE for Users");
    } else {
        log ("Error executting query");
    }
    if (checkAdminExist() == false) {
        log ("No admin user found! Creating new one");
        createUser("Admin", "admin", "admin", true);
    }
}

bool DbWorker::createUser(QString name, QString login, QString password, bool isAdmin)
{
    QSqlQuery query;
    query.prepare("INSERT INTO users(name, login, password, isAdmin) VALUES (:name, :login, :password, :isAdmin);");
    query.bindValue(":name", name);
    query.bindValue(":login", login);
    query.bindValue(":password", password);
    query.bindValue(":isAdmin", isAdmin);
    bool ok = query.exec();
    if (ok) {
        log ("Successfully added user");
    } else {
        log ("Error executting query");
    }
    return ok;
}

User DbWorker::loginUser(QString login, QString password)
{
    User user;
    user.id = -1;
    QSqlQuery query(QString("SELECT * FROM users WHERE login='%1' AND password='%2';")
                    .arg(login)
                    .arg(password));
    if (query.exec()) {
        log ("Successfully executed user login");
    } else {
        log ("Error executting query");
    }
    while (query.next()) {
        user.id = query.value("id").toInt();
        user.login = query.value("login").toString();
        user.name = query.value("name").toString();
        user.isAdmin = query.value("isAdmin").toBool();
    }
    return user;
}

void DbWorker::log(QString message)
{
    qDebug() << "[DBWORKER]: " << message;
}

bool DbWorker::checkAdminExist()
{
    QSqlQuery query("SELECT * FROM users WHERE login='admin';");
    if (query.exec()) {
        log ("Successfully executed admin check");
    } else {
        log ("Error executting query");
    }
    while (query.next())
        return true;
    return false;
}
