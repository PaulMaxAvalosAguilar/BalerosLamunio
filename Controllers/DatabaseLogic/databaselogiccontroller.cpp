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

}

