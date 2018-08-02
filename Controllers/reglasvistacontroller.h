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

public slots:
    void addChildren();

public:
    void showAddDialog(const QModelIndex &index);


private:
    ReglasVista * vista;
    QTreeWidgetItem *topItem;

public:

};

#endif // REGLASVISTACONTROLLER_H
