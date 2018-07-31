#include "BaseDatos/DAOs/categoriadao.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>

#include "BaseDatos/ENTITIES/categoria.h"
#include "BaseDatos/DatabaseManager/databasemanager.h"

using namespace std;

CategoriaDao::CategoriaDao(QSqlDatabase& database) :
    QObject(),
    mDatabase(database)
{
}

void CategoriaDao::init() const
{
    if (!mDatabase.tables().contains("Categoria")) {
        QSqlQuery query(mDatabase);
        query.exec("CREATE TABLE Categoria (id INTEGER PRIMARY KEY AUTOINCREMENT, nombre TEXT,regla_ID INTEGER)");
        DatabaseManager::debugQuery(query);
    }
}

void CategoriaDao::addRecord(Categoria& record)
{
    QSqlQuery query(mDatabase);
    query.prepare("INSERT INTO Categoria (nombre,regla_ID)  VALUES  (:nombre,:regla_ID)");
    query.bindValue(":nombre", record.getNombre());
    query.bindValue(":regla_ID", record.getRegla_ID());
    query.exec();
    record.setId(query.lastInsertId().toInt());
    DatabaseManager::debugQuery(query);
    emit addedRecord();
}

void CategoriaDao::updateRecord(Categoria& record)
{
    QSqlQuery query(mDatabase);
    query.prepare("UPDATE Categoria SET (nombre,regla_ID) = (:nombre,:regla_ID) WHERE  id = (:id)");
    query.bindValue(":nombre", record.getNombre());
    query.bindValue(":regla_ID", record.getRegla_ID());
    query.bindValue(":id", record.getId());
    query.exec();
    DatabaseManager::debugQuery(query);
    emit updatedRecord();
}

void CategoriaDao::removeRecord(int recordId)
{
    QSqlQuery query(mDatabase);
    query.prepare("DELETE FROM Categoria WHERE id = (:id)");
    query.bindValue(":id", recordId);
    query.exec();
    DatabaseManager::debugQuery(query);
    emit removedRecord();
}

unique_ptr<vector<unique_ptr<Categoria>>> CategoriaDao::getRecord(int recordId) const
{
    QSqlQuery query(mDatabase);
    query.prepare("SELECT * FROM Categoria WHERE id = (:id)");
    query.bindValue(":id", recordId);
    query.exec();
    DatabaseManager::debugQuery(query);
    unique_ptr<vector<unique_ptr<Categoria>>> list(new vector<unique_ptr<Categoria>>());
    while(query.next()) {
        std::unique_ptr<Categoria> categoria(new Categoria());
        categoria->setId(query.value("id").toInt());
        categoria->setNombre(query.value("nombre").toString());
        categoria->setRegla_ID(query.value("regla_ID").toInt());
        list->push_back(move(categoria));
    }
    return list;
}

void CategoriaDao::removeAllRecords()
{
    QSqlQuery query("DELETE FROM Categoria", mDatabase);
    query.exec();
    DatabaseManager::debugQuery(query);
    emit removedAllRecords();
}

unique_ptr<vector<unique_ptr<Categoria>>> CategoriaDao::getAllRecords() const
{
    QSqlQuery query("SELECT * FROM Categoria", mDatabase);
    query.exec();
    DatabaseManager::debugQuery(query);
    unique_ptr<vector<unique_ptr<Categoria>>> list(new vector<unique_ptr<Categoria>>());
    while(query.next()) {
        unique_ptr<Categoria> categoria(new Categoria());
        categoria->setId(query.value("id").toInt());
        categoria->setNombre(query.value("nombre").toString());
        categoria->setRegla_ID(query.value("regla_ID").toInt());
        list->push_back(move(categoria));
    }
    return list;
}

void CategoriaDao::createIndexonColumnNombre()const
{
    QSqlQuery query("create index nombre on Categoria(nombre)", mDatabase);
    query.exec();
    DatabaseManager::debugQuery(query);
}

void CategoriaDao::createIndexonColumnRegla_ID() const
{
    QSqlQuery query("create index regla_ID on Categoria(regla_ID)", mDatabase);
    query.exec();
    DatabaseManager::debugQuery(query);
}
