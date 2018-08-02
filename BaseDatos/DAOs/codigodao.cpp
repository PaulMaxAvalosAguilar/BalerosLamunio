#include "BaseDatos/DAOs/codigodao.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>

#include "BaseDatos/ENTITIES/codigo.h"
#include "BaseDatos/DatabaseManager/databasemanager.h"

using namespace std;

CodigoDao::CodigoDao(QSqlDatabase& database) :
    QObject(),
    mDatabase(database)
{
}

void CodigoDao::init() const
{
    if (!mDatabase.tables().contains("Codigo")) {
        QSqlQuery query(mDatabase);
        query.exec("CREATE TABLE Codigo (id INTEGER PRIMARY KEY AUTOINCREMENT, caracteres TEXT,subcategoria_ID INTEGER)");
        DatabaseManager::debugQuery(query);
    }
}

void CodigoDao::addRecord(Codigo& record)
{
    QSqlQuery query(mDatabase);
    query.prepare("INSERT INTO Codigo (caracteres,subcategoria_ID)  VALUES  (:caracteres,:subcategoria_ID)");
    query.bindValue(":caracteres", record.getCaracteres());
    query.bindValue(":subcategoria_ID", record.getSubcategoria_ID());
    query.exec();
    record.setId(query.lastInsertId().toInt());
    DatabaseManager::debugQuery(query);
    emit addedRecord();
}

void CodigoDao::updateRecord(Codigo& record)
{
    QSqlQuery query(mDatabase);
    query.prepare("UPDATE Codigo SET (caracteres,subcategoria_ID) = (:caracteres,:subcategoria_ID) WHERE  id = (:id)");
    query.bindValue(":caracteres", record.getCaracteres());
    query.bindValue(":subcategoria_ID", record.getSubcategoria_ID());
    query.bindValue(":id", record.getId());
    query.exec();
    DatabaseManager::debugQuery(query);
    emit updatedRecord();
}

void CodigoDao::removeRecord(int recordId)
{
    QSqlQuery query(mDatabase);
    query.prepare("DELETE FROM Codigo WHERE id = (:id)");
    query.bindValue(":id", recordId);
    query.exec();
    DatabaseManager::debugQuery(query);
    emit removedRecord();
}

unique_ptr<vector<unique_ptr<Codigo>>> CodigoDao::getRecord(int recordId) const
{
    QSqlQuery query(mDatabase);
    query.prepare("SELECT * FROM Codigo WHERE id = (:id)");
    query.bindValue(":id", recordId);
    query.exec();
    DatabaseManager::debugQuery(query);
    unique_ptr<vector<unique_ptr<Codigo>>> list(new vector<unique_ptr<Codigo>>());
    while(query.next()) {
        std::unique_ptr<Codigo> codigo(new Codigo());
        codigo->setId(query.value("id").toInt());
        codigo->setCaracteres(query.value("caracteres").toString());
        codigo->setSubcategoria_ID(query.value("subcategoria_ID").toInt());
        list->push_back(move(codigo));
    }
    return list;
}

void CodigoDao::removeAllRecords()
{
    QSqlQuery query("DELETE FROM Codigo", mDatabase);
    query.exec();
    DatabaseManager::debugQuery(query);
    emit removedAllRecords();
}

unique_ptr<vector<unique_ptr<Codigo>>> CodigoDao::getAllRecords() const
{
    QSqlQuery query("SELECT * FROM Codigo", mDatabase);
    query.exec();
    DatabaseManager::debugQuery(query);
    unique_ptr<vector<unique_ptr<Codigo>>> list(new vector<unique_ptr<Codigo>>());
    while(query.next()) {
        unique_ptr<Codigo> codigo(new Codigo());
        codigo->setId(query.value("id").toInt());
        codigo->setCaracteres(query.value("caracteres").toString());
        codigo->setSubcategoria_ID(query.value("subcategoria_ID").toInt());
        list->push_back(move(codigo));
    }
    return list;
}

std::unique_ptr<std::vector<std::unique_ptr<Codigo> > > CodigoDao::getAllRecordsbySubcategoria(int recordId) const
{
    QSqlQuery query(mDatabase);
    query.prepare("SELECT * FROM Codigo WHERE subcategoria_ID = (:id)");
    query.bindValue(":id", recordId);
    query.exec();
    DatabaseManager::debugQuery(query);
    unique_ptr<vector<unique_ptr<Codigo>>> list(new vector<unique_ptr<Codigo>>());
    while(query.next()) {
        std::unique_ptr<Codigo> codigo(new Codigo());
        codigo->setId(query.value("id").toInt());
        codigo->setCaracteres(query.value("caracteres").toString());
        codigo->setSubcategoria_ID(query.value("subcategoria_ID").toInt());
        list->push_back(move(codigo));
    }
    return list;
}

void CodigoDao::createIndexonColumnCaracteres(){
    QSqlQuery query("create index caracteres on Codigo(caracteres)", mDatabase);
    query.exec();
    DatabaseManager::debugQuery(query);
}

void CodigoDao::createIndexonColumnSubcategoria_ID(){
    QSqlQuery query("create index subcategoria_ID on Codigo(subcategoria_ID)", mDatabase);
    query.exec();
    DatabaseManager::debugQuery(query);
}
