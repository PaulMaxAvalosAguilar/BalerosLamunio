#include "BaseDatos/DAOs/clasificaciondao.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>

#include "BaseDatos/ENTITIES/clasificacion.h"
#include "BaseDatos/DatabaseManager/databasemanager.h"

using namespace std;

ClasificacionDao::ClasificacionDao(QSqlDatabase& database) :
    QObject(),
    mDatabase(database)
{
}

void ClasificacionDao::init() const
{
    if (!mDatabase.tables().contains("Clasificacion")) {
        QSqlQuery query(mDatabase);
        query.exec("CREATE TABLE Clasificacion (id INTEGER PRIMARY KEY AUTOINCREMENT, subcategoria_ID INTEGER,coreplusmodifier_ID INTEGER)");
        DatabaseManager::debugQuery(query);
    }
}

void ClasificacionDao::addRecord(Clasificacion& record)
{
    QSqlQuery query(mDatabase);
    query.prepare("INSERT INTO Clasificacion (subcategoria_ID,coreplusmodifier_ID)  VALUES  (:subcategoria_ID,:coreplusmodifier_ID)");
    query.bindValue(":subcategoria_ID", record.getSubcategoria_ID());
    query.bindValue(":coreplusmodifier_ID", record.getCoreplusmodifier_ID());
    query.exec();
    record.setId(query.lastInsertId().toInt());
    DatabaseManager::debugQuery(query);
    emit addedRecord();
}

void ClasificacionDao::updateRecord(Clasificacion& record)
{
    QSqlQuery query(mDatabase);
    query.prepare("UPDATE Clasificacion SET (subcategoria_ID,coreplusmodifier_ID) = (:subcategoria_ID,:coreplusmodifier_ID) WHERE  id = (:id)");
    query.bindValue(":subcategoria_ID", record.getSubcategoria_ID());
    query.bindValue(":coreplusmodifier_ID", record.getCoreplusmodifier_ID());
    query.bindValue(":id", record.getId());
    query.exec();
    DatabaseManager::debugQuery(query);
    emit updatedRecord();
}

void ClasificacionDao::removeRecord(int recordId)
{
    QSqlQuery query(mDatabase);
    query.prepare("DELETE FROM Clasificacion WHERE id = (:id)");
    query.bindValue(":id", recordId);
    query.exec();
    DatabaseManager::debugQuery(query);
    emit removedRecord();
}

unique_ptr<vector<unique_ptr<Clasificacion>>> ClasificacionDao::getRecord(int recordId) const
{
    QSqlQuery query(mDatabase);
    query.prepare("SELECT * FROM Clasificacion WHERE id = (:id)");
    query.bindValue(":id", recordId);
    query.exec();
    DatabaseManager::debugQuery(query);
    unique_ptr<vector<unique_ptr<Clasificacion>>> list(new vector<unique_ptr<Clasificacion>>());
    while(query.next()) {
        std::unique_ptr<Clasificacion> clasificacion(new Clasificacion());
        clasificacion->setId(query.value("id").toInt());
        clasificacion->setSubcategoria_ID(query.value("subcategoria_ID").toInt());
        clasificacion->setCoreplusmodifier_ID(query.value("coreplusmodifier_ID").toInt());
        list->push_back(move(clasificacion));
    }
    return list;
}

void ClasificacionDao::removeAllRecords()
{
    QSqlQuery query("DELETE FROM Clasificacion", mDatabase);
    query.exec();
    DatabaseManager::debugQuery(query);
    emit removedAllRecords();
}

unique_ptr<vector<unique_ptr<Clasificacion>>> ClasificacionDao::getAllRecords() const
{
    QSqlQuery query("SELECT * FROM Clasificacion", mDatabase);
    query.exec();
    DatabaseManager::debugQuery(query);
    unique_ptr<vector<unique_ptr<Clasificacion>>> list(new vector<unique_ptr<Clasificacion>>());
    while(query.next()) {
        unique_ptr<Clasificacion> clasificacion(new Clasificacion());
        clasificacion->setId(query.value("id").toInt());
        clasificacion->setSubcategoria_ID(query.value("subcategoria_ID").toInt());
        clasificacion->setCoreplusmodifier_ID(query.value("coreplusmodifier_ID").toInt());
        list->push_back(move(clasificacion));
    }
    return list;
}

void ClasificacionDao::createIndexonColumnSubcategoria_ID(){
    QSqlQuery query("create index subcategoria_ID on Clasificacion(subcategoria_ID)", mDatabase);
    query.exec();
    DatabaseManager::debugQuery(query);
}

void ClasificacionDao::createIndexonColumnCoreplusmodifier_ID(){
    QSqlQuery query("create index coreplusmodifier_ID on Clasificacion(coreplusmodifier_ID)", mDatabase);
    query.exec();
    DatabaseManager::debugQuery(query);
}
