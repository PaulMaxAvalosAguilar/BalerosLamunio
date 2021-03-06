#include "databasemanager.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>

DatabaseManager&DatabaseManager::instance()
{
    static DatabaseManager singleton;
    return singleton;
}

DatabaseManager::~DatabaseManager()
{
    mDatabase->close();
}

void DatabaseManager::debugQuery(const QSqlQuery& query)
{
    if (query.lastError().type() == QSqlError::ErrorType::NoError) {
        qDebug() << "Query OK:"  << query.lastQuery();
    } else {
        qWarning() << "Query KO:" << query.lastError().text();
        qWarning() << "Query text:" << query.lastQuery();
    }
}

DatabaseManager::DatabaseManager(const QString& path) :
    mDatabase(new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE"))),
    regladao(*mDatabase),
    categoriadao(*mDatabase),
    subcategoriadao(*mDatabase),
    codigodao(*mDatabase),
    corebearingdao(*mDatabase),
    coreplusmodifierdao(*mDatabase),
    clasificaciondao(*mDatabase)
{
    mDatabase->setDatabaseName(path);
    bool openStatus = mDatabase->open();
    qDebug() << "Database connection: " << (openStatus ? "OK" : "Error");

    regladao.init();
    categoriadao.init();
    subcategoriadao.init();
    codigodao.init();
    corebearingdao.init();
    coreplusmodifierdao.init();
    clasificaciondao.init();

}

