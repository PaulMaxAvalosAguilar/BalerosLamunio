#include "BaseDatos/DAOs/regladao.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>

#include "BaseDatos/ENTITIES/regla.h"
#include "BaseDatos/DatabaseManager/databasemanager.h"

using namespace std;

ReglaDao::ReglaDao(QSqlDatabase& database) :
    QObject(),
    mDatabase(database)
{
}

void ReglaDao::init() const
{
    if (!mDatabase.tables().contains("Regla")) {
        QSqlQuery query(mDatabase);
        query.exec("CREATE TABLE Regla (id INTEGER PRIMARY KEY AUTOINCREMENT, nombre TEXT)");
        DatabaseManager::debugQuery(query);
    }
}

void ReglaDao::addRecord(Regla& record)
{
    QSqlQuery query(mDatabase);
    query.prepare("INSERT INTO Regla (nombre)  VALUES  (:nombre)");
    query.bindValue(":nombre", record.getNombre());
    query.exec();
    record.setId(query.lastInsertId().toInt());
    DatabaseManager::debugQuery(query);
    emit addedRecord();
}

void ReglaDao::updateRecord(Regla& record)
{
    QSqlQuery query(mDatabase);
    query.prepare("UPDATE Regla SET (nombre) = (:nombre) WHERE  id = (:id)");
    query.bindValue(":nombre", record.getNombre());
    query.bindValue(":id", record.getId());
    query.exec();
    DatabaseManager::debugQuery(query);
    emit updatedRecord();
}

void ReglaDao::removeRecord(int recordId)
{
    QSqlQuery query(mDatabase);
    query.prepare("DELETE FROM Regla WHERE id = (:id)");
    query.bindValue(":id", recordId);
    query.exec();
    DatabaseManager::debugQuery(query);
    emit removedRecord();
}

unique_ptr<vector<unique_ptr<Regla>>> ReglaDao::getRecord(int recordId) const
{
    QSqlQuery query(mDatabase);
    query.prepare("SELECT * FROM Regla WHERE id = (:id)");
    query.bindValue(":id", recordId);
    query.exec();
    DatabaseManager::debugQuery(query);
    unique_ptr<vector<unique_ptr<Regla>>> list(new vector<unique_ptr<Regla>>());
    while(query.next()) {
        std::unique_ptr<Regla> regla(new Regla());
        regla->setId(query.value("id").toInt());
        regla->setNombre(query.value("nombre").toString());
        list->push_back(move(regla));
    }
    return list;
}

void ReglaDao::removeAllRecords()
{
    QSqlQuery query("DELETE FROM Regla", mDatabase);
    query.exec();
    DatabaseManager::debugQuery(query);
    emit removedAllRecords();
}

unique_ptr<vector<unique_ptr<Regla>>> ReglaDao::getAllRecords() const
{
    QSqlQuery query("SELECT * FROM Regla", mDatabase);
    query.exec();
    DatabaseManager::debugQuery(query);
    unique_ptr<vector<unique_ptr<Regla>>> list(new vector<unique_ptr<Regla>>());
    while(query.next()) {
        unique_ptr<Regla> regla(new Regla());
        regla->setId(query.value("id").toInt());
        regla->setNombre(query.value("nombre").toString());
        list->push_back(move(regla));
    }
    return list;
}

void ReglaDao::createIndexonColumnNombre(){
    QSqlQuery query("create index nombre on Regla(nombre)", mDatabase);
    query.exec();
    DatabaseManager::debugQuery(query);
}
