#include "categoria.h"

Categoria::Categoria()
{

}

int Categoria::getId() const
{
    return id;
}

void Categoria::setId(int value)
{
    id = value;
}

QString Categoria::getNombre() const
{
    return nombre;
}

void Categoria::setNombre(const QString &value)
{
    nombre = value;
}

int Categoria::getRegla_ID() const
{
    return regla_ID;
}

void Categoria::setRegla_ID(int value)
{
    regla_ID = value;
}
