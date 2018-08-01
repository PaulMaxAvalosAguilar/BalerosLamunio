#ifndef DATABASELOGICCONTROLLER_H
#define DATABASELOGICCONTROLLER_H

#include <QString>
#include <memory>
#include <vector>
#include "BaseDatos/ENTITIES/regla.h"
#include "BaseDatos/ENTITIES/categoria.h"
#include "BaseDatos/ENTITIES/subcategoria.h"
#include "BaseDatos/ENTITIES/codigo.h"

#include "BaseDatos/DatabaseManager/databasemanager.h"

class DatabaseLogicController
{
public:
    DatabaseLogicController();
    virtual ~DatabaseLogicController();

    void addRegla(QString nombre);
    void updateRegla(int id, QString nombre);
    void removeRegla(int id);
    std::unique_ptr<std::vector<std::unique_ptr<Regla>>> getReglas();

    void addCategoria(QString nombre, int reglaid);
    void updateCategoria(int id, QString nombre, int reglaid);
    void removeCategoria(int id);
    std::unique_ptr<std::vector<std::unique_ptr<Categoria>>> getCategorias();

private:
    DatabaseManager &man;
};

#endif // DATABASELOGICCONTROLLER_H
