#include "BaseDatos/DAOs/coreplusmodifierdao.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>

#include "BaseDatos/ENTITIES/coreplusmodifier.h"
#include "BaseDatos/DatabaseManager/databasemanager.h"

using namespace std;

CoreplusmodifierDao::CoreplusmodifierDao(QSqlDatabase& database) :
    QObject(),
    mDatabase(database)
{
}

void CoreplusmodifierDao::init() const
{
    if (!mDatabase.tables().contains("Coreplusmodifier")) {
        QSqlQuery query(mDatabase);
        query.exec("CREATE TABLE Coreplusmodifier (id INTEGER PRIMARY KEY AUTOINCREMENT, fullNombre TEXT,coreBearing_ID INTEGER)");
        DatabaseManager::debugQuery(query);
    }
}

void CoreplusmodifierDao::addRecord(Coreplusmodifier& record)
{
    QSqlQuery query(mDatabase);
    query.prepare("INSERT INTO Coreplusmodifier (fullNombre,coreBearing_ID)  VALUES  (:fullNombre,:coreBearing_ID)");
    query.bindValue(":fullNombre", record.getFullNombre());
    query.bindValue(":coreBearing_ID", record.getCoreBearing_ID());
    query.exec();
    record.setId(query.lastInsertId().toInt());
    DatabaseManager::debugQuery(query);
    emit addedRecord();
}

void CoreplusmodifierDao::updateRecord(Coreplusmodifier& record)
{
    QSqlQuery query(mDatabase);
    query.prepare("UPDATE Coreplusmodifier SET (fullNombre,coreBearing_ID) = (:fullNombre,:coreBearing_ID) WHERE  id = (:id)");
    query.bindValue(":fullNombre", record.getFullNombre());
    query.bindValue(":coreBearing_ID", record.getCoreBearing_ID());
    query.bindValue(":id", record.getId());
    query.exec();
    DatabaseManager::debugQuery(query);
    emit updatedRecord();
}

void CoreplusmodifierDao::removeRecord(int recordId)
{
    QSqlQuery query(mDatabase);
    query.prepare("DELETE FROM Coreplusmodifier WHERE id = (:id)");
    query.bindValue(":id", recordId);
    query.exec();
    DatabaseManager::debugQuery(query);
    emit removedRecord();
}

unique_ptr<vector<unique_ptr<Coreplusmodifier>>> CoreplusmodifierDao::getRecord(int recordId) const
{
    QSqlQuery query(mDatabase);
    query.prepare("SELECT * FROM Coreplusmodifier WHERE id = (:id)");
    query.bindValue(":id", recordId);
    query.exec();
    DatabaseManager::debugQuery(query);
    unique_ptr<vector<unique_ptr<Coreplusmodifier>>> list(new vector<unique_ptr<Coreplusmodifier>>());
    while(query.next()) {
        std::unique_ptr<Coreplusmodifier> coreplusmodifier(new Coreplusmodifier());
        coreplusmodifier->setId(query.value("id").toInt());
        coreplusmodifier->setFullNombre(query.value("fullNombre").toString());
        coreplusmodifier->setCoreBearing_ID(query.value("coreBearing_ID").toInt());
        list->push_back(move(coreplusmodifier));
    }
    return list;
}

void CoreplusmodifierDao::removeAllRecords()
{
    QSqlQuery query("DELETE FROM Coreplusmodifier", mDatabase);
    query.exec();
    DatabaseManager::debugQuery(query);
    emit removedAllRecords();
}

unique_ptr<vector<unique_ptr<Coreplusmodifier>>> CoreplusmodifierDao::getAllRecords() const
{
    QSqlQuery query("SELECT * FROM Coreplusmodifier", mDatabase);
    query.exec();
    DatabaseManager::debugQuery(query);
    unique_ptr<vector<unique_ptr<Coreplusmodifier>>> list(new vector<unique_ptr<Coreplusmodifier>>());
    while(query.next()) {
        unique_ptr<Coreplusmodifier> coreplusmodifier(new Coreplusmodifier());
        coreplusmodifier->setId(query.value("id").toInt());
        coreplusmodifier->setFullNombre(query.value("fullNombre").toString());
        coreplusmodifier->setCoreBearing_ID(query.value("coreBearing_ID").toInt());
        list->push_back(move(coreplusmodifier));
    }
    return list;
}

void CoreplusmodifierDao::createIndexonColumnFullNombre(){
    QSqlQuery query("create index fullNombre on Coreplusmodifier(fullNombre)", mDatabase);
    query.exec();
    DatabaseManager::debugQuery(query);
}

void CoreplusmodifierDao::createIndexonColumnCoreBearing_ID(){
    QSqlQuery query("create index coreBearing_ID on Coreplusmodifier(coreBearing_ID)", mDatabase);
    query.exec();
    DatabaseManager::debugQuery(query);
}

