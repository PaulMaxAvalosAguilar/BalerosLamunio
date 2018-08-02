#include "reglasvistacontroller.h"
#include "Vistas/reglasvista.h"
#include "Vistas/Dialog/aniadircategoriadialog.h"
#include <QDebug>

using namespace std;


ReglasVistaController::ReglasVistaController(ReglasVista *vista):
    DatabaseLogicController(),
    vista(vista)
{
    addChildren();

    connect(&man.categoriadao, &CategoriaDao::addedRecord, this, &ReglasVistaController::addChildren);
}


void ReglasVistaController::addChildren()
{
    //Limpiar el árbol
    vista->clearTreeWidget();

    //Añadir un topWidget
    QTreeWidgetItem *topItem = new QTreeWidgetItem();
    topItem->setText(0,"Reglas");
    vista->addTopLevelItem(topItem);

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
            regla->setId(listaReglas->at(i)->getId());
            regla->setNombre(listaReglas->at(i)->getNombre());

            //Crear QTreeWidgetItem para Regla
            QTreeWidgetItem *reglasItem = new QTreeWidgetItem();
            reglasItem->setData(0, Qt::UserRole,QVariant::fromValue(*regla));
            reglasItem->setText(0, regla->getNombre());

            vista->addChildToParent(topItem, reglasItem);




            //Leer todas las categorías de la base de datos
            unique_ptr<vector<unique_ptr<Categoria>>> listaCategorias =
                    std::move(getCategoriasByReglasId(regla->getId()));

            //checar que la lista de categorias no este vacía
            if(!listaCategorias->empty()){

                //Por cada regla crear un objeto de tipo regla y
                //añadirlo a QTreeWidgetItem
                for(uint i = 0; i < listaCategorias->size();i++){

                    //Crear nuevo objeto de clase categoria
                    Categoria *categoria = new Categoria();
                    categoria->setId(listaCategorias->at(i)->getId());
                    categoria->setNombre(listaCategorias->at(i)->getNombre());                    
                    categoria->setRegla_ID(regla->getId());

                    //Crear QTreeWidgetItem para Categoria
                    QTreeWidgetItem *categoriaItem = new QTreeWidgetItem();
                    categoriaItem->setData(0, Qt::UserRole, QVariant::fromValue(*categoria));
                    categoriaItem->setText(0, categoria->getNombre());

                    vista->addChildToParent(reglasItem, categoriaItem);




                    //Leer todas las subcategorias
                    unique_ptr<vector<unique_ptr<Subcategoria>>> listaSubCategorias =
                            std::move(getSubcategoriasByCategoriaId(categoria->getId()));

                    //Checar que la lista de subcategorias no este vacía
                    if(!listaSubCategorias->empty()){


                        //Por cada regla crear un objeto de tipo regla y
                        //añadirlo a QTreeWidgetItem
                        for(uint i = 0; i < listaSubCategorias->size(); i++){
                            //Crear nuevo objeto de clase subcategoria
                            Subcategoria *subcategoria = new Subcategoria();
                            subcategoria->setId(listaSubCategorias->at(i)->getId());
                            subcategoria->setNombre(listaSubCategorias->at(i)->getNombre());
                            subcategoria->setCategoria_ID(categoria->getId());

                            //Crear QTreeWidgetItem para subcategoria
                            QTreeWidgetItem *subcategoriaItem = new QTreeWidgetItem();
                            subcategoriaItem->setData(0, Qt::UserRole, QVariant::fromValue(*subcategoria));
                            subcategoriaItem->setText(0, subcategoria->getNombre());

                            vista->addChildToParent(categoriaItem, subcategoriaItem);
                        }
                    }
                }
            }
        }
    }
}

void ReglasVistaController::showAddDialog(const QModelIndex &index)
{
    if(index.data(Qt::UserRole).canConvert<Regla>()){
        qDebug()<<"Puede convertir a regla";

        Regla regla = index.data(Qt::UserRole).value<Regla>();

        int result;

        AniadirCategoriaDialog dal;
        dal.setWindowTitle("Añadir categoria");
        result = dal.exec();

        if(result == QDialog::Rejected)
            return;

        addCategoria(dal.getNombre(), regla.getId());


    }else if(index.data(Qt::UserRole).canConvert<Categoria>()){
        qDebug()<<"Puede convertir a categoria";
    }else if(index.data(Qt::UserRole).canConvert<Subcategoria>()){
        qDebug()<<"Puede convertir a subcategoria";
    }
}


