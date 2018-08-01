#include "databaselogiccontroller.h"

DatabaseLogicController::DatabaseLogicController():
    man(DatabaseManager::instance())
{

}

DatabaseLogicController::~DatabaseLogicController()
{

}

void DatabaseLogicController::addRegla(QString nombre)
{

}

void DatabaseLogicController::updateRegla(int id, QString nombre)
{

}

void DatabaseLogicController::removeRegla(int id)
{

}

std::unique_ptr<std::vector<std::unique_ptr<Regla> > > DatabaseLogicController::getReglas()
{
    //Leer todas las reglas
    return man.regladao.getAllRecords();
}

void DatabaseLogicController::addCategoria(QString nombre, int reglaid)
{

}

void DatabaseLogicController::updateCategoria(int id, QString nombre, int reglaid)
{

}

void DatabaseLogicController::removeCategoria(int id)
{

}

std::unique_ptr<std::vector<std::unique_ptr<Categoria> > > DatabaseLogicController::getCategorias()
{
    //Leer todas las categorias
    return man.categoriadao.getAllRecords();
}

