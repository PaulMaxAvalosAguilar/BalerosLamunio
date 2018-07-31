#ifndef DATABASELOGICCONTROLLER_H
#define DATABASELOGICCONTROLLER_H

#include <QString>
#include <memory>
#include <vector>
#include "BaseDatos/ENTITIES/regla.h"

#include "BaseDatos/DatabaseManager/databasemanager.h"

class DatabaseLogicController
{
public:
    DatabaseLogicController();

    void addRegla(QString nombre);
    void updateRegla(int id, QString nombre);
    void removeRegla(int id);
    std::unique_ptr<std::vector<std::unique_ptr<Regla>>> getReglas();


private:
    DatabaseManager &man;
};

#endif // DATABASELOGICCONTROLLER_H
