#ifndef CATEGORIA_H
#define CATEGORIA_H

#include <QString>


class Categoria
{
public:
    Categoria();

    int getId() const;
    void setId(int value);

    QString getNombre() const;
    void setNombre(const QString &value);

    int getRegla_ID() const;
    void setRegla_ID(int value);

private:
    int id;
    QString nombre;
    int regla_ID;
};

#endif // CATEGORIA_H
