#include "reglasvistacontroller.h"
#include "Vistas/reglasvista.h"
#include "Vistas/Dialog/categoriadialog.h"
#include "Vistas/Dialog/regladialog.h"
#include "Vistas/Dialog/subcategoriadialog.h"
#include "Vistas/Dialog/codigodialog.h"
#include <QTreeWidgetItem>
#include <QTableWidgetItem>
#include <QDebug>

using namespace std;


ReglasVistaController::ReglasVistaController(ReglasVista *vista):
    DatabaseLogicController(),
    vista(vista)
{
    addChildren();


    //Regla Signals
    connect(&man.regladao, &ReglaDao::addedRecord, this, &ReglasVistaController::addChildren);
    connect(&man.regladao, &ReglaDao::updatedRecord, this, &ReglasVistaController::addChildren);
    connect(&man.regladao, &ReglaDao::removedRecord, this, &ReglasVistaController::addChildren);

    //Categoria Signals
    connect(&man.categoriadao, &CategoriaDao::addedRecord, this, &ReglasVistaController::addChildren);
    connect(&man.categoriadao, &CategoriaDao::updatedRecord, this, &ReglasVistaController::addChildren);
    connect(&man.categoriadao, &CategoriaDao::removedRecord, this, &ReglasVistaController::addChildren);

    //Subcategoria Signals
    connect(&man.subcategoriadao, &SubcategoriaDao::addedRecord, this, &ReglasVistaController::addChildren);
    connect(&man.subcategoriadao, &SubcategoriaDao::updatedRecord, this, &ReglasVistaController::addChildren);
    connect(&man.subcategoriadao, &SubcategoriaDao::removedRecord, this, &ReglasVistaController::addChildren);

    //Codigo Signals
    connect(&man.codigodao, &CodigoDao::addedRecord, this, &ReglasVistaController::fillTable);
    connect(&man.codigodao, &CodigoDao::updatedRecord, this, &ReglasVistaController::fillTable);
    connect(&man.codigodao, &CodigoDao::removedRecord, this, &ReglasVistaController::fillTable);
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
            unique_ptr<Regla> regla(new Regla);
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
                    unique_ptr<Categoria> categoria(new Categoria);
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
                            unique_ptr<Subcategoria> subcategoria(new Subcategoria);
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

        Regla regla = index.data(Qt::UserRole).value<Regla>();

        int result;

        CategoriaDialog dal;
        dal.setWindowTitle("Añadir categoria");
        result = dal.exec();

        if(result == QDialog::Rejected)
            return;

        addCategoria(dal.getNombre(), regla.getId());


    }else if(index.data(Qt::UserRole).canConvert<Categoria>()){
        Categoria categoria = index.data(Qt::UserRole).value<Categoria>();

        int result;
        SubcategoriaDialog dal;
        dal.setWindowTitle("Añadir subcategoria");
        result = dal.exec();

        if(result == QDialog::Rejected)
            return;

        addSubcategoria(dal.getNombre(), categoria.getId());

    }else if(index.data(Qt::UserRole).canConvert<Subcategoria>()){

    }else{
        int result;
        ReglaDialog dal;
        dal.setWindowTitle("Añadir regla");
        result = dal.exec();

        if(result == QDialog::Rejected)
            return;

        addRegla(dal.getNombre());
    }
}

void ReglasVistaController::showupdateDialog(const QModelIndex &index)
{
    if(index.data(Qt::UserRole).canConvert<Regla>()){

        Regla regla = index.data(Qt::UserRole).value<Regla>();

        int result;

        ReglaDialog dal;
        dal.setWindowTitle("Actualizar regla");
        dal.setNombre(regla.getNombre());
        result = dal.exec();

        if(result == QDialog::Rejected)
            return;

        updateRegla(regla.getId(), dal.getNombre());

    }else if(index.data(Qt::UserRole).canConvert<Categoria>()){
        Categoria categoria = index.data(Qt::UserRole).value<Categoria>();

        int result;
        CategoriaDialog dal;
        dal.setWindowTitle("Actualizar categoria");
        dal.setNombre(categoria.getNombre());
        result = dal.exec();

        if(result == QDialog::Rejected)
            return;

        updateCategoria(categoria.getId(), dal.getNombre(), categoria.getRegla_ID());

    }else if(index.data(Qt::UserRole).canConvert<Subcategoria>()){
        Subcategoria subcategoria = index.data(Qt::UserRole).value<Subcategoria>();

        int result;
        CategoriaDialog dal;
        dal.setWindowTitle("Actualizar subcategoria");
        dal.setNombre(subcategoria.getNombre());
        result = dal.exec();

        if(result == QDialog::Rejected)
            return;

        updateSubcategoria(subcategoria.getId(), dal.getNombre(), subcategoria.getCategoria_ID());
    }else{

    }
}

void ReglasVistaController::removeAction(const QModelIndex &index)
{
    if(index.data(Qt::UserRole).canConvert<Regla>()){

        Regla regla = index.data(Qt::UserRole).value<Regla>();
        removeRegla(regla.getId());

    }else if(index.data(Qt::UserRole).canConvert<Categoria>()){
        Categoria categoria = index.data(Qt::UserRole).value<Categoria>();
        removeCategoria(categoria.getId());

    }else if(index.data(Qt::UserRole).canConvert<Subcategoria>()){
        Subcategoria subcategoria = index.data(Qt::UserRole).value<Subcategoria>();
        removeSubcategoria(subcategoria.getId());

    }else{

    }
}

void ReglasVistaController::muestraDatosTabla(const QModelIndex &index)
{
    if(index.data(Qt::UserRole).canConvert<Subcategoria>()){

        Subcategoria subcat = index.data(Qt::UserRole).value<Subcategoria>();
        subcatToDisplay =  subcat.getId();
        fillTable();

    }else{
        vista->clearTableWidget();
    }
}

void ReglasVistaController::fillTable()
{
    unique_ptr<vector<unique_ptr<Codigo>>> listaCodigos
            = getCodigosbySubcategoriaId(subcatToDisplay);
    vista->clearTableWidget();

    if(!listaCodigos->empty()){
        vector<QTableWidgetItem *> codigosList;

        for(uint i = 0; i < listaCodigos->size(); i++){

            unique_ptr<Codigo> code(new Codigo);
            code->setId(listaCodigos->at(i)->getId());
            code->setCaracteres(listaCodigos->at(i)->getCaracteres());
            code->setSubcategoria_ID(listaCodigos->at(i)->getSubcategoria_ID());

            QTableWidgetItem *codigoItem = new QTableWidgetItem();
            codigoItem->setData(Qt::UserRole, QVariant::fromValue(*code));
            codigoItem->setText(code->getCaracteres());

            codigosList.push_back(codigoItem);
        }
        vista->addDatatoTable(codigosList);

    }
}

void ReglasVistaController::aniadeDatosTabla(const QModelIndex &index)
{
    if(index.data(Qt::UserRole).canConvert<Subcategoria>()){

        Subcategoria subcat = index.data(Qt::UserRole).value<Subcategoria>();

        int result;
        CodigoDialog dal;
        dal.setWindowTitle("Añadir codigo");

        result = dal.exec();

        if(result == QDialog::Rejected){
            return;
        }

        addCodigo(dal.getCaracteres(), subcat.getId());

    }
}

void ReglasVistaController::actualizaDatoTabla(const QModelIndex &indexTree,
                                               const QModelIndex &indexTable)
{
    if(indexTree.data(Qt::UserRole).canConvert<Subcategoria>()){

        if(indexTable.data(Qt::UserRole).canConvert<Codigo>()){
            Subcategoria subcat = indexTree.data(Qt::UserRole).value<Subcategoria>();
            Codigo code = indexTable.data(Qt::UserRole).value<Codigo>();


            int result;
            CodigoDialog dal;
            dal.setCaracteres(code.getCaracteres());
            dal.setWindowTitle("Actualizar codigo");

            result = dal.exec();

            if(result == QDialog::Rejected){
                return;
            }

            updateCodigo( code.getId(), dal.getCaracteres(), subcat.getId());
        }
    }
}

void ReglasVistaController::eleiminarDatoTabla(const QModelIndex &indexTable)
{

        if(indexTable.data(Qt::UserRole).canConvert<Codigo>()){
            Codigo code = indexTable.data(Qt::UserRole).value<Codigo>();


            int result;
            CodigoDialog dal;
            dal.setCaracteres(code.getCaracteres());
            dal.setWindowTitle("Eliminar codigo");

            result = dal.exec();

            if(result == QDialog::Rejected){
                return;
            }

            removeCodigo(code.getId());
        }
}



