#ifndef REGLASVISTACONTROLLER_H
#define REGLASVISTACONTROLLER_H

#include "Controllers/DatabaseLogic/databaselogiccontroller.h"
#include <QTreeWidgetItem>

class ReglasVista;

class ReglasVistaController : public DatabaseLogicController
{
public:
    ReglasVistaController(ReglasVista *vista);

    void fillParentTree();
    void addChildren();


private:
    ReglasVista * vista;
    QTreeWidgetItem *parentitem;

};

#endif // REGLASVISTACONTROLLER_H
