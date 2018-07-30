#ifndef REGLA_H
#define REGLA_H

#include <QString>

class Regla
{
public:
    Regla();


    int getId() const;
    void setId(int value);

    QString getNombre() const;
    void setNombre(const QString &value);

private:
    int id;
    QString nombre;
};

#endif // REGLA_H
