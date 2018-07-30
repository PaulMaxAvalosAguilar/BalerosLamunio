#include "subcategoria.h"

Subcategoria::Subcategoria()
{

}

int Subcategoria::getId() const
{
    return id;
}

void Subcategoria::setId(int value)
{
    id = value;
}

QString Subcategoria::getNombre() const
{
    return nombre;
}

void Subcategoria::setNombre(const QString &value)
{
    nombre = value;
}

int Subcategoria::getCategoria_ID() const
{
    return categoria_ID;
}

void Subcategoria::setCategoria_ID(int value)
{
    categoria_ID = value;
}
