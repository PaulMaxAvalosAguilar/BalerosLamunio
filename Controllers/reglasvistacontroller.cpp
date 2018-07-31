#include "reglasvistacontroller.h"
#include <QTreeWidgetItem>
#include <Vistas/reglasvista.h>

ReglasVistaController::ReglasVistaController(ReglasVista *vista):
    DatabaseLogicController(),
    vista(vista)
{

}

void ReglasVistaController::fillParentTree()
{
    QTreeWidgetItem *item = new QTreeWidgetItem();
    item->setText(0, "Reglas");
    vista->addTopLevelItem(item);
}

