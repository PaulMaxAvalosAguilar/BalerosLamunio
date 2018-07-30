#include "regla.h"

Regla::Regla()
{

}

int Regla::getId() const
{
    return id;
}

void Regla::setId(int value)
{
    id = value;
}

QString Regla::getNombre() const
{
    return nombre;
}

void Regla::setNombre(const QString &value)
{
    nombre = value;
}

