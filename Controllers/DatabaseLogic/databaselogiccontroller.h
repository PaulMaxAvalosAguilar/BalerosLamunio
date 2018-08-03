#ifndef DATABASELOGICCONTROLLER_H
#define DATABASELOGICCONTROLLER_H

#include <QObject>
#include <QString>
#include <memory>
#include <vector>
#include "BaseDatos/ENTITIES/regla.h"
#include "BaseDatos/ENTITIES/categoria.h"
#include "BaseDatos/ENTITIES/subcategoria.h"
#include "BaseDatos/ENTITIES/codigo.h"

#include "BaseDatos/DatabaseManager/databasemanager.h"

class DatabaseLogicController : public QObject
{

    Q_OBJECT

public:
    DatabaseLogicController();
    virtual ~DatabaseLogicController();

    void addRegla(QString nombre);
    void updateRegla(int id, QString nombre);
    void removeRegla(int id);
    std::unique_ptr<std::vector<std::unique_ptr<Regla>>> getRegla(int id);
    std::unique_ptr<std::vector<std::unique_ptr<Regla>>> getReglas();

    void addCategoria(QString nombre, int reglaid);
    void updateCategoria(int id, QString nombre, int reglaid);
    void removeCategoria(int id);
    std::unique_ptr<std::vector<std::unique_ptr<Categoria>>> getCategoria(int id);
    std::unique_ptr<std::vector<std::unique_ptr<Categoria>>> getCategorias();
    std::unique_ptr<std::vector<std::unique_ptr<Categoria>>>
    getCategoriasByReglasId(int reglaId);

    void addSubcategoria(QString nombre, int categoriaid);
    void updateSubcategoria(int id, QString nombre, int categoriaid);
    void removeSubcategoria(int id);
    std::unique_ptr<std::vector<std::unique_ptr<Subcategoria>>> getSubcategoria(int id);
    std::unique_ptr<std::vector<std::unique_ptr<Subcategoria>>> getSubcategorias();
    std::unique_ptr<std::vector<std::unique_ptr<Subcategoria>>>
    getSubcategoriasByCategoriaId(int categoriaId);

    void addCodigo(QString caracteres, int subcategoriaid);
    void updateCodigo(int id,  QString caracteres, int subcategoriaid);
    void removeCodigo(int id);
    std::unique_ptr<std::vector<std::unique_ptr<Codigo>>> getCodigo(int id);
    std::unique_ptr<std::vector<std::unique_ptr<Codigo>>> getCodigos();
    std::unique_ptr<std::vector<std::unique_ptr<Codigo>>>
    getCodigosbySubcategoriaId(int subcategoriaId);

protected:
    DatabaseManager &man;
};

#endif // DATABASELOGICCONTROLLER_H
