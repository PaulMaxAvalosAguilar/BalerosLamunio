#include "coreplusmodifiers.h"

Coreplusmodifiers::Coreplusmodifiers()
{

}

int Coreplusmodifiers::getId() const
{
    return id;
}

void Coreplusmodifiers::setId(int value)
{
    id = value;
}

QString Coreplusmodifiers::getFullNombre() const
{
    return fullNombre;
}

void Coreplusmodifiers::setFullNombre(const QString &value)
{
    fullNombre = value;
}

int Coreplusmodifiers::getCoreBearing_ID() const
{
    return coreBearing_ID;
}

void Coreplusmodifiers::setCoreBearing_ID(int value)
{
    coreBearing_ID = value;
}
