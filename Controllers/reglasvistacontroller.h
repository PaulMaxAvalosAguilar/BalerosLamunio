#ifndef REGLASVISTACONTROLLER_H
#define REGLASVISTACONTROLLER_H

#include "Controllers/DatabaseLogic/databaselogiccontroller.h"

class ReglasVista;

class ReglasVistaController : public DatabaseLogicController
{
public:
    ReglasVistaController();
    void configureVista(ReglasVista *vista);

private:
    ReglasVista * vista;
};

#endif // REGLASVISTACONTROLLER_H
