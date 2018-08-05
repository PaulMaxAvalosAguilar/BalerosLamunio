#ifndef REGLASVISTACONTROLLER_H
#define REGLASVISTACONTROLLER_H

#include "Controllers/DatabaseLogic/databaselogiccontroller.h"

class ReglasVista;

class ReglasVistaController : public DatabaseLogicController
{
public:
    ReglasVistaController(ReglasVista *vista);


public slots:
    void addChildren();
    void fillTable();

public:
    void showAddDialog(const QModelIndex &index);
    void showupdateDialog(const QModelIndex &index);
    void removeAction(const QModelIndex &index);

    void muestraDatosTabla(const QModelIndex &index);
    void aniadeDatosTabla(const QModelIndex &index);

private:
    ReglasVista * vista;
    int subcatToDisplay;

public:

};

#endif // REGLASVISTACONTROLLER_H
