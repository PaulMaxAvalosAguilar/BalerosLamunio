#include "reglasvistacontroller.h"
#include <Vistas/reglasvista.h>

using namespace std;

ReglasVistaController::ReglasVistaController(ReglasVista *vista):
    DatabaseLogicController(),
    vista(vista)
{
    fillParentTree();
    addChildren();
    man.regladao.createIndexonColumnNombre();
}

void ReglasVistaController::fillParentTree()
{
    parentitem = new QTreeWidgetItem();
    parentitem->setText(0,"Reglas");
    vista->addTopLevelItem(parentitem);
}

void ReglasVistaController::addChildren()
{
    //leer todas las reglas de la base de datos
    unique_ptr<vector<unique_ptr<Regla>>> listaReglas =
            std::move(getReglas());

    //chechar que la lista de reglas no esté vacía
    if(!listaReglas->empty()){

        //Por cada regla crear un objeto de tipo regla y
        //añadirlo a QTreeWidgetItem
        for(uint i = 0; i < listaReglas->size(); i++){

            //Crear nueva objeto de clase regla
            Regla *regla = new Regla();
            regla->setNombre(listaReglas->at(i)->getNombre());
            regla->setId(listaReglas->at(i)->getId());

            //Crear QTreeWidgetItem para Regla
            QTreeWidgetItem *reglasItem = new QTreeWidgetItem();
            reglasItem->setData(0, Qt::UserRole,QVariant::fromValue(*regla));
            reglasItem->setText(0, regla->getNombre());

            vista->addChildToParent(parentitem, reglasItem);

            //Leer todas las categorías de la base de datos
            unique_ptr<vector<unique_ptr<Categoria>>> listaCategorias =
                    std::move(this->getCategoriasByReglasId(regla->getId()));

            //checar que al lista de categorias no este vacía
            if(!listaCategorias->empty()){

                //Por cada regla crear un objeto de tipo regla y
                //añadirlo a QTreeWidgetItem
                for(uint i = 0; i < listaCategorias->size();i++){

                //Crear nuevo objeto de

                }
            }
        }
    }

}

