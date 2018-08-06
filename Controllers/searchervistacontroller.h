#ifndef SEARCHERCONTROLLER_H
#define SEARCHERCONTROLLER_H

#include "Controllers/DatabaseLogic/databaselogiccontroller.h"

class SearcherVista;

class SearcherVistaController : DatabaseLogicController
{
public:
    SearcherVistaController(SearcherVista *vista);

private:
    SearcherVista *vista;
};

#endif // SEARCHERCONTROLLER_H
