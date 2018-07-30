#include "BaseDatos/DAOs/subcategoriadao.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>

#include "BaseDatos/ENTITIES/subcategoria.h"
#include "BaseDatos/DatabaseManager/databasemanager.h"

using namespace std;

SubcategoriaDao::SubcategoriaDao(QSqlDatabase& database) :
    QObject(),
    mDatabase(database)
{
}

void SubcategoriaDao::init() const
{
    if (!mDatabase.tables().contains("Subcategoria")) {
        QSqlQuery query(mDatabase);
        query.exec("CREATE TABLE Subcategoria (id INTEGER PRIMARY KEY AUTOINCREMENT, nombre TEXT,categoria_ID INTEGER)");
        DatabaseManager::debugQuery(query);
    }
}

void SubcategoriaDao::addRecord(Subcategoria& record)
{
    QSqlQuery query(mDatabase);
    query.prepare("INSERT INTO Subcategoria (nombre,categoria_ID)  VALUES  (:nombre,:categoria_ID)");
    query.bindValue(":nombre", record.getNombre());
    query.bindValue(":categoria_ID", record.getCategoria_ID());
    query.exec();
    record.setId(query.lastInsertId().toInt());
    DatabaseManager::debugQuery(query);
    emit addedRecord();
}

void SubcategoriaDao::updateRecord(Subcategoria& record)
{
    QSqlQuery query(mDatabase);
    query.prepare("UPDATE Subcategoria SET (nombre,categoria_ID) = (:nombre,:categoria_ID) WHERE  id = (:id)");
    query.bindValue(":nombre", record.getNombre());
    query.bindValue(":categoria_ID", record.getCategoria_ID());
    query.bindValue(":id", record.getId());
    query.exec();
    DatabaseManager::debugQuery(query);
    emit updatedRecord();
}

void SubcategoriaDao::removeRecord(int recordId)
{
    QSqlQuery query(mDatabase);
    query.prepare("DELETE FROM Subcategoria WHERE id = (:id)");
    query.bindValue(":id", recordId);
    query.exec();
    DatabaseManager::debugQuery(query);
    emit removedRecord();
}

unique_ptr<vector<unique_ptr<Subcategoria>>> SubcategoriaDao::getRecord(int recordId) const
{
    QSqlQuery query(mDatabase);
    query.prepare("SELECT * FROM Subcategoria WHERE id = (:id)");
    query.bindValue(":id", recordId);
    query.exec();
    DatabaseManager::debugQuery(query);
    unique_ptr<vector<unique_ptr<Subcategoria>>> list(new vector<unique_ptr<Subcategoria>>());
    while(query.next()) {
        std::unique_ptr<Subcategoria> subcategoria(new Subcategoria());
        subcategoria->setId(query.value("id").toInt());
        subcategoria->setNombre(query.value("nombre").toString());
        subcategoria->setCategoria_ID(query.value("categoria_ID").toInt());
        list->push_back(move(subcategoria));
    }
    return list;
}

void SubcategoriaDao::removeAllRecords()
{
    QSqlQuery query("DELETE FROM Subcategoria", mDatabase);
    query.exec();
    DatabaseManager::debugQuery(query);
    emit removedAllRecords();
}

unique_ptr<vector<unique_ptr<Subcategoria>>> SubcategoriaDao::getAllRecords() const
{
    QSqlQuery query("SELECT * FROM Subcategoria", mDatabase);
    query.exec();
    DatabaseManager::debugQuery(query);
    unique_ptr<vector<unique_ptr<Subcategoria>>> list(new vector<unique_ptr<Subcategoria>>());
    while(query.next()) {
        unique_ptr<Subcategoria> subcategoria(new Subcategoria());
        subcategoria->setId(query.value("id").toInt());
        subcategoria->setNombre(query.value("nombre").toString());
        subcategoria->setCategoria_ID(query.value("categoria_ID").toInt());
        list->push_back(move(subcategoria));
    }
    return list;
}

void SubcategoriaDao::createIndexonColumnNombre(){
    QSqlQuery query("create index nombre on Subcategoria(nombre)", mDatabase);
    query.exec();
    DatabaseManager::debugQuery(query);
}

void SubcategoriaDao::createIndexonColumnCategoria_ID(){
    QSqlQuery query("create index categoria_ID on Subcategoria(categoria_ID)", mDatabase);
    query.exec();
    DatabaseManager::debugQuery(query);
}

