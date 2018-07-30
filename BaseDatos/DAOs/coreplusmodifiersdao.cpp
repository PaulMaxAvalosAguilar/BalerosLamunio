#include "BaseDatos/DAOs/coreplusmodifiersdao.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>

#include "BaseDatos/ENTITIES/coreplusmodifiers.h"
#include "BaseDatos/DatabaseManager/databasemanager.h"

using namespace std;

CoreplusmodifiersDao::CoreplusmodifiersDao(QSqlDatabase& database) :
    QObject(),
    mDatabase(database)
{
}

void CoreplusmodifiersDao::init() const
{
    if (!mDatabase.tables().contains("Coreplusmodifiers")) {
        QSqlQuery query(mDatabase);
        query.exec("CREATE TABLE Coreplusmodifiers (id INTEGER PRIMARY KEY AUTOINCREMENT, fullNombre TEXT,coreBearing_ID INTEGER)");
        DatabaseManager::debugQuery(query);
    }
}

void CoreplusmodifiersDao::addRecord(Coreplusmodifiers& record)
{
    QSqlQuery query(mDatabase);
    query.prepare("INSERT INTO Coreplusmodifiers (fullNombre,coreBearing_ID)  VALUES  (:fullNombre,:coreBearing_ID)");
    query.bindValue(":fullNombre", record.getFullNombre());
    query.bindValue(":coreBearing_ID", record.getCoreBearing_ID());
    query.exec();
    record.setId(query.lastInsertId().toInt());
    DatabaseManager::debugQuery(query);
    emit addedRecord();
}

void CoreplusmodifiersDao::updateRecord(Coreplusmodifiers& record)
{
    QSqlQuery query(mDatabase);
    query.prepare("UPDATE Coreplusmodifiers SET (fullNombre,coreBearing_ID) = (:fullNombre,:coreBearing_ID) WHERE  id = (:id)");
    query.bindValue(":fullNombre", record.getFullNombre());
    query.bindValue(":coreBearing_ID", record.getCoreBearing_ID());
    query.bindValue(":id", record.getId());
    query.exec();
    DatabaseManager::debugQuery(query);
    emit updatedRecord();
}

void CoreplusmodifiersDao::removeRecord(int recordId)
{
    QSqlQuery query(mDatabase);
    query.prepare("DELETE FROM Coreplusmodifiers WHERE id = (:id)");
    query.bindValue(":id", recordId);
    query.exec();
    DatabaseManager::debugQuery(query);
    emit removedRecord();
}

unique_ptr<vector<unique_ptr<Coreplusmodifiers>>> CoreplusmodifiersDao::getRecord(int recordId) const
{
    QSqlQuery query(mDatabase);
    query.prepare("SELECT * FROM Coreplusmodifiers WHERE id = (:id)");
    query.bindValue(":id", recordId);
    query.exec();
    DatabaseManager::debugQuery(query);
    unique_ptr<vector<unique_ptr<Coreplusmodifiers>>> list(new vector<unique_ptr<Coreplusmodifiers>>());
    while(query.next()) {
        std::unique_ptr<Coreplusmodifiers> coreplusmodifiers(new Coreplusmodifiers());
        coreplusmodifiers->setId(query.value("id").toInt());
        coreplusmodifiers->setFullNombre(query.value("fullNombre").toString());
        coreplusmodifiers->setCoreBearing_ID(query.value("coreBearing_ID").toInt());
        list->push_back(move(coreplusmodifiers));
    }
    return list;
}

void CoreplusmodifiersDao::removeAllRecords()
{
    QSqlQuery query("DELETE FROM Coreplusmodifiers", mDatabase);
    query.exec();
    DatabaseManager::debugQuery(query);
    emit removedAllRecords();
}

unique_ptr<vector<unique_ptr<Coreplusmodifiers>>> CoreplusmodifiersDao::getAllRecords() const
{
    QSqlQuery query("SELECT * FROM Coreplusmodifiers", mDatabase);
    query.exec();
    DatabaseManager::debugQuery(query);
    unique_ptr<vector<unique_ptr<Coreplusmodifiers>>> list(new vector<unique_ptr<Coreplusmodifiers>>());
    while(query.next()) {
        unique_ptr<Coreplusmodifiers> coreplusmodifiers(new Coreplusmodifiers());
        coreplusmodifiers->setId(query.value("id").toInt());
        coreplusmodifiers->setFullNombre(query.value("fullNombre").toString());
        coreplusmodifiers->setCoreBearing_ID(query.value("coreBearing_ID").toInt());
        list->push_back(move(coreplusmodifiers));
    }
    return list;
}

void CoreplusmodifiersDao::createIndexonColumnFullNombre(){
    QSqlQuery query("create index fullNombre on Coreplusmodifiers(fullNombre)", mDatabase);
    query.exec();
    DatabaseManager::debugQuery(query);
}

void CoreplusmodifiersDao::createIndexonColumnCoreBearing_ID(){
    QSqlQuery query("create index coreBearing_ID on Coreplusmodifiers(coreBearing_ID)", mDatabase);
    query.exec();
    DatabaseManager::debugQuery(query);
}
