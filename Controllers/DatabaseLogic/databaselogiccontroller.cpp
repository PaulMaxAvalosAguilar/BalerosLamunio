#include "databaselogiccontroller.h"
#include <QMessageBox>

using namespace std;

DatabaseLogicController::DatabaseLogicController():
    QObject(),
    man(DatabaseManager::instance())
{

}

DatabaseLogicController::~DatabaseLogicController()
{

}

void DatabaseLogicController::addRegla(QString nombre)
{
    //Check not null values
    if(nombre.isEmpty()){
     QMessageBox box;
     box.setText("No has ingresado un nombre");
     box.exec();
     return;
    }

    //Build Object

    Regla regla;
    regla.setNombre(nombre);
    man.regladao.addRecord(regla);
}

void DatabaseLogicController::updateRegla(int id, QString nombre)
{
    //Check not null values
    if(nombre.isEmpty()){
     QMessageBox box;
     box.setText("No has ingresado un nombre");
     box.exec();
     return;
    }

    //Build Object

    Regla regla;
    regla.setId(id);
    regla.setNombre(nombre);
    man.regladao.updateRecord(regla);
}

void DatabaseLogicController::removeRegla(int id)
{

    //Delete dependencies in cascade
    std::unique_ptr<vector<std::unique_ptr<Categoria>>> listaCategorias
            = man.categoriadao.getAllRecordsByRegla(id);

    if(!listaCategorias->empty()){
        for(uint i = 0; i < listaCategorias->size(); i++){
            removeCategoria(listaCategorias->at(i)->getId());
        }
    }

    //Delete record
    man.regladao.removeRecord(id);
}

std::unique_ptr<std::vector<std::unique_ptr<Regla> > > DatabaseLogicController::getRegla(int id)
{
    return man.regladao.getRecord(id);
}

std::unique_ptr<std::vector<std::unique_ptr<Regla> > > DatabaseLogicController::getReglas()
{
    //Leer todas las reglas
    return man.regladao.getAllRecords();
}

void DatabaseLogicController::addCategoria(QString nombre, int reglaid)
{
    //Check not null values
    if(nombre.isEmpty()){
     QMessageBox box;
     box.setText("No has ingresado un nombre");
     box.exec();
     return;
    }

    //Build object
    Categoria categoria;
    categoria.setNombre(nombre);
    categoria.setRegla_ID(reglaid);

    man.categoriadao.addRecord(categoria);
}

void DatabaseLogicController::updateCategoria(int id, QString nombre, int reglaid)
{
    //Check not null values
    if(nombre.isEmpty()){
     QMessageBox box;
     box.setText("No has ingresado un nombre");
     box.exec();
     return;
    }

    //Build Object

    Categoria categoria;
    categoria.setId(id);
    categoria.setNombre(nombre);
    categoria.setRegla_ID(reglaid);
    man.categoriadao.updateRecord(categoria);
}

void DatabaseLogicController::removeCategoria(int id)
{
    //Delete dependencies in cascade
    std::unique_ptr<vector<std::unique_ptr<Subcategoria>>> listasubcategorias
            = man.subcategoriadao.getAllRecordsbyCategoria(id);

    if(!listasubcategorias->empty()){
        for(uint i = 0; i < listasubcategorias->size(); i++){
            removeSubcategoria(listasubcategorias->at(i)->getId());
        }
    }

    //Delete record
    man.categoriadao.removeRecord(id);
}

std::unique_ptr<std::vector<std::unique_ptr<Categoria> > > DatabaseLogicController::getCategoria(int id)
{
    return man.categoriadao.getRecord(id);
}

std::unique_ptr<std::vector<std::unique_ptr<Categoria> > > DatabaseLogicController::getCategorias()
{
    //Leer todas las categorias
    return man.categoriadao.getAllRecords();
}

std::unique_ptr<std::vector<std::unique_ptr<Categoria> > > DatabaseLogicController::getCategoriasByReglasId(int reglaId)
{
    //Leer todas las categorías por Regla
    return man.categoriadao.getAllRecordsByRegla(reglaId);
}

void DatabaseLogicController::addSubcategoria(QString nombre, int categoriaid)
{
    //Check not null values
    if(nombre.isEmpty()){
     QMessageBox box;
     box.setText("No has ingresado un nombre");
     box.exec();
     return;
    }

    //Build object
    Subcategoria subcategoria;
    subcategoria.setNombre(nombre);
    subcategoria.setCategoria_ID(categoriaid);

    man.subcategoriadao.addRecord(subcategoria);
}

void DatabaseLogicController::updateSubcategoria(int id, QString nombre, int categoriaid)
{
    //Check not null values
    if(nombre.isEmpty()){
     QMessageBox box;
     box.setText("No has ingresado un nombre");
     box.exec();
     return;
    }

    //Build Object

    Subcategoria subcategoria;
    subcategoria.setId(id);
    subcategoria.setNombre(nombre);
    subcategoria.setCategoria_ID(categoriaid);
    man.subcategoriadao.updateRecord(subcategoria);
}

void DatabaseLogicController::removeSubcategoria(int id)
{
    //Delete dependencies in cascade
    std::unique_ptr<vector<std::unique_ptr<Codigo>>> listacodigos
            = man.codigodao.getAllRecordsbySubcategoria(id);

    if(!listacodigos->empty()){
        for(uint i = 0; i < listacodigos->size(); i++){
            removeCodigo(listacodigos->at(i)->getId());
        }
    }

    //Delete record
    man.subcategoriadao.removeRecord(id);
}

std::unique_ptr<std::vector<std::unique_ptr<Subcategoria> > > DatabaseLogicController::getSubcategoria(int id)
{
    return man.subcategoriadao.getRecord(id);
}

std::unique_ptr<std::vector<std::unique_ptr<Subcategoria> > > DatabaseLogicController::getSubcategorias()
{
    //Leer todas las subcategorias
    return man.subcategoriadao.getAllRecords();
}

std::unique_ptr<std::vector<std::unique_ptr<Subcategoria> > > DatabaseLogicController::getSubcategoriasByCategoriaId(int categoriaId)
{
    //Leer todas las subcategorias por categoria
    return man.subcategoriadao.getAllRecordsbyCategoria(categoriaId);
}


void DatabaseLogicController::addCodigo(QString caracteres, int subcategoriaid)
{

}

void DatabaseLogicController::updateCodigo(int id, QString caracteres, int subcategoriaid)
{

}

void DatabaseLogicController::removeCodigo(int id)
{
    //Delete record
    man.codigodao.removeRecord(id);
}

std::unique_ptr<std::vector<std::unique_ptr<Codigo> > > DatabaseLogicController::getCodigo(int id)
{
    return man.codigodao.getRecord(id);
}

std::unique_ptr<std::vector<std::unique_ptr<Codigo> > > DatabaseLogicController::getCodigos()
{
    //Leer todos los codigos
    return man.codigodao.getAllRecords();
}

std::unique_ptr<std::vector<std::unique_ptr<Codigo> > > DatabaseLogicController::getCodigosbySubcategoriaId(int subcategoriaId)
{
    //Leer todos los códigos por subcategoria
    return man.codigodao.getAllRecordsbySubcategoria(subcategoriaId);
}

