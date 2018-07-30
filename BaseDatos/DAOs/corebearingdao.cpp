#include "BaseDatos/DAOs/corebearingdao.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>

#include "BaseDatos/ENTITIES/corebearing.h"
#include "BaseDatos/DatabaseManager/databasemanager.h"

using namespace std;

CorebearingDao::CorebearingDao(QSqlDatabase& database) :
    QObject(),
    mDatabase(database)
{
}

void CorebearingDao::init() const
{
    if (!mDatabase.tables().contains("Corebearing")) {
        QSqlQuery query(mDatabase);
        query.exec("CREATE TABLE Corebearing (id INTEGER PRIMARY KEY AUTOINCREMENT, coreValue TEXT,diamInterno INTEGER,diamExterno INTEGER,espesura INTEGER,regla_ID INTEGER)");
        DatabaseManager::debugQuery(query);
    }
}

void CorebearingDao::addRecord(Corebearing& record)
{
    QSqlQuery query(mDatabase);
    query.prepare("INSERT INTO Corebearing (coreValue,diamInterno,diamExterno,espesura,regla_ID)  VALUES  (:coreValue,:diamInterno,:diamExterno,:espesura,:regla_ID)");
    query.bindValue(":coreValue", record.getCoreValue());
    query.bindValue(":diamInterno", record.getDiamInterno());
    query.bindValue(":diamExterno", record.getDiamExterno());
    query.bindValue(":espesura", record.getEspesura());
    query.bindValue(":regla_ID", record.getRegla_ID());
    query.exec();
    record.setId(query.lastInsertId().toInt());
    DatabaseManager::debugQuery(query);
    emit addedRecord();
}

void CorebearingDao::updateRecord(Corebearing& record)
{
    QSqlQuery query(mDatabase);
    query.prepare("UPDATE Corebearing SET (coreValue,diamInterno,diamExterno,espesura,regla_ID) = (:coreValue,:diamInterno,:diamExterno,:espesura,:regla_ID) WHERE  id = (:id)");
    query.bindValue(":coreValue", record.getCoreValue());
    query.bindValue(":diamInterno", record.getDiamInterno());
    query.bindValue(":diamExterno", record.getDiamExterno());
    query.bindValue(":espesura", record.getEspesura());
    query.bindValue(":regla_ID", record.getRegla_ID());
    query.bindValue(":id", record.getId());
    query.exec();
    DatabaseManager::debugQuery(query);
    emit updatedRecord();
}

void CorebearingDao::removeRecord(int recordId)
{
    QSqlQuery query(mDatabase);
    query.prepare("DELETE FROM Corebearing WHERE id = (:id)");
    query.bindValue(":id", recordId);
    query.exec();
    DatabaseManager::debugQuery(query);
    emit removedRecord();
}

unique_ptr<vector<unique_ptr<Corebearing>>> CorebearingDao::getRecord(int recordId) const
{
    QSqlQuery query(mDatabase);
    query.prepare("SELECT * FROM Corebearing WHERE id = (:id)");
    query.bindValue(":id", recordId);
    query.exec();
    DatabaseManager::debugQuery(query);
    unique_ptr<vector<unique_ptr<Corebearing>>> list(new vector<unique_ptr<Corebearing>>());
    while(query.next()) {
        std::unique_ptr<Corebearing> corebearing(new Corebearing());
        corebearing->setId(query.value("id").toInt());
        corebearing->setCoreValue(query.value("coreValue").toString());
        corebearing->setDiamInterno(query.value("diamInterno").toInt());
        corebearing->setDiamExterno(query.value("diamExterno").toInt());
        corebearing->setEspesura(query.value("espesura").toInt());
        corebearing->setRegla_ID(query.value("regla_ID").toInt());
        list->push_back(move(corebearing));
    }
    return list;
}

void CorebearingDao::removeAllRecords()
{
    QSqlQuery query("DELETE FROM Corebearing", mDatabase);
    query.exec();
    DatabaseManager::debugQuery(query);
    emit removedAllRecords();
}

unique_ptr<vector<unique_ptr<Corebearing>>> CorebearingDao::getAllRecords() const
{
    QSqlQuery query("SELECT * FROM Corebearing", mDatabase);
    query.exec();
    DatabaseManager::debugQuery(query);
    unique_ptr<vector<unique_ptr<Corebearing>>> list(new vector<unique_ptr<Corebearing>>());
    while(query.next()) {
        unique_ptr<Corebearing> corebearing(new Corebearing());
        corebearing->setId(query.value("id").toInt());
        corebearing->setCoreValue(query.value("coreValue").toString());
        corebearing->setDiamInterno(query.value("diamInterno").toInt());
        corebearing->setDiamExterno(query.value("diamExterno").toInt());
        corebearing->setEspesura(query.value("espesura").toInt());
        corebearing->setRegla_ID(query.value("regla_ID").toInt());
        list->push_back(move(corebearing));
    }
    return list;
}

void CorebearingDao::createIndexonColumnCoreValue(){
    QSqlQuery query("create index coreValue on Corebearing(coreValue)", mDatabase);
    query.exec();
    DatabaseManager::debugQuery(query);
}

void CorebearingDao::createIndexonColumnDiamInterno(){
    QSqlQuery query("create index diamInterno on Corebearing(diamInterno)", mDatabase);
    query.exec();
    DatabaseManager::debugQuery(query);
}

void CorebearingDao::createIndexonColumnDiamExterno(){
    QSqlQuery query("create index diamExterno on Corebearing(diamExterno)", mDatabase);
    query.exec();
    DatabaseManager::debugQuery(query);
}

void CorebearingDao::createIndexonColumnEspesura(){
    QSqlQuery query("create index espesura on Corebearing(espesura)", mDatabase);
    query.exec();
    DatabaseManager::debugQuery(query);
}

void CorebearingDao::createIndexonColumnRegla_ID(){
    QSqlQuery query("create index regla_ID on Corebearing(regla_ID)", mDatabase);
    query.exec();
    DatabaseManager::debugQuery(query);
}
