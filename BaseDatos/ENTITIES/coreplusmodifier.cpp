#include "coreplusmodifier.h"

Coreplusmodifier::Coreplusmodifier()
{

}

int Coreplusmodifier::getId() const
{
    return id;
}

void Coreplusmodifier::setId(int value)
{
    id = value;
}

QString Coreplusmodifier::getFullNombre() const
{
    return fullNombre;
}

void Coreplusmodifier::setFullNombre(const QString &value)
{
    fullNombre = value;
}

int Coreplusmodifier::getCoreBearing_ID() const
{
    return coreBearing_ID;
}

void Coreplusmodifier::setCoreBearing_ID(int value)
{
    coreBearing_ID = value;
}
