#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <memory>

#include <QString>

#include "BaseDatos/DAOs/regladao.h"
#include "BaseDatos/DAOs/categoriadao.h"
#include "BaseDatos/DAOs/subcategoriadao.h"
#include "BaseDatos/DAOs/codigodao.h"
#include "BaseDatos/DAOs/corebearingdao.h"
#include "BaseDatos/DAOs/coreplusmodifierdao.h"
#include "BaseDatos/DAOs/clasificaciondao.h"

class QSqlQuery;
class QSqlDatabase;

const QString DATABASE_FILENAME = "LamuñoDatabase";

class DatabaseManager
{
public:
    static DatabaseManager& instance();
    ~DatabaseManager();

    static void debugQuery(const QSqlQuery& query);

protected:
    DatabaseManager(const QString& path = DATABASE_FILENAME);
private:
    std::unique_ptr<QSqlDatabase> mDatabase;

public://Add your DAO's as public members
    ReglaDao regladao;
    CategoriaDao categoriadao;
    SubcategoriaDao subcategoriadao;
    CodigoDao codigodao;
    CorebearingDao corebearingdao;
    CoreplusmodifierDao coreplusmodifierdao;
    ClasificacionDao clasificaciondao;

};

#endif // DATABASEMANAGER_H
