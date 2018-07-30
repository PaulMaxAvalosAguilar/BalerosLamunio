#include "corebearing.h"

Corebearing::Corebearing()
{

}

int Corebearing::getId() const
{
    return id;
}

void Corebearing::setId(int value)
{
    id = value;
}

QString Corebearing::getCoreValue() const
{
    return coreValue;
}

void Corebearing::setCoreValue(const QString &value)
{
    coreValue = value;
}

int Corebearing::getDiamInterno() const
{
    return diamInterno;
}

void Corebearing::setDiamInterno(int value)
{
    diamInterno = value;
}

int Corebearing::getDiamExterno() const
{
    return diamExterno;
}

void Corebearing::setDiamExterno(int value)
{
    diamExterno = value;
}

int Corebearing::getEspesura() const
{
    return espesura;
}

void Corebearing::setEspesura(int value)
{
    espesura = value;
}

int Corebearing::getRegla_ID() const
{
    return regla_ID;
}

void Corebearing::setRegla_ID(int value)
{
    regla_ID = value;
}
