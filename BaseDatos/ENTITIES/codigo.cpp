#include "codigo.h"

Codigo::Codigo()
{

}

int Codigo::getId() const
{
    return id;
}

void Codigo::setId(int value)
{
    id = value;
}

QString Codigo::getCaracteres() const
{
    return caracteres;
}

void Codigo::setCaracteres(const QString &value)
{
    caracteres = value;
}

int Codigo::getSubcategoria_ID() const
{
    return subcategoria_ID;
}

void Codigo::setSubcategoria_ID(int value)
{
    subcategoria_ID = value;
}
