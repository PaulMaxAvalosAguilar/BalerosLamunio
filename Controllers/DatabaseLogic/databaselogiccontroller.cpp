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

std::unique_ptr<std::vector<std::unique_ptr<Categoria> > > DatabaseLogicController::getCategoriasByReglasId(int reglaId)
{
    //Leer todas las categorías por Regla
    return man.categoriadao.getAllRecordsByRegla(reglaId);
}

void DatabaseLogicController::addSubcategoria(QString nombre, int categoriaid)
{

}

void DatabaseLogicController::updateSubcategoria(int id, QString nombre, int categoriaid)
{

}

void DatabaseLogicController::removeSubcategoria(int id)
{

}

std::unique_ptr<std::vector<std::unique_ptr<Subcategoria> > > DatabaseLogicController::getSubcategorias()
{
 //Leer todas las subcategorias
    return man.subcategoriadao.getAllRecords();
}

void DatabaseLogicController::addCodigo(QString caracteres, int subcategoriaid)
{

}

void DatabaseLogicController::updateCodigo(int id, QString caracteres, int subcategoriaid)
{

}

void DatabaseLogicController::removeCodigo(int id)
{

}

std::unique_ptr<std::vector<std::unique_ptr<Codigo> > > DatabaseLogicController::getCodigo()
{
    //Leer todos los codigos
    return man.codigodao.getAllRecords();
}

