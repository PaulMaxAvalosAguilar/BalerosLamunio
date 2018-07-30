#include "clasificacion.h"

Clasificacion::Clasificacion()
{

}

int Clasificacion::getId() const
{
    return id;
}

void Clasificacion::setId(int value)
{
    id = value;
}

int Clasificacion::getSubcategoria_ID() const
{
    return subcategoria_ID;
}

void Clasificacion::setSubcategoria_ID(int value)
{
    subcategoria_ID = value;
}

int Clasificacion::getCoreplusmodifier_ID() const
{
    return coreplusmodifier_ID;
}

void Clasificacion::setCoreplusmodifier_ID(int value)
{
    coreplusmodifier_ID = value;
}
