#ifndef SUBCATEGORIA_H
#define SUBCATEGORIA_H

#include <QString>
#include <QMetaType>

class Subcategoria
{
public:
    Subcategoria();

    int getId() const;
    void setId(int value);

    QString getNombre() const;
    void setNombre(const QString &value);

    int getCategoria_ID() const;
    void setCategoria_ID(int value);

private:
    int id;
    QString nombre;
    int categoria_ID;
};

Q_DECLARE_METATYPE(Subcategoria)

#endif // SUBCATEGORIA_H
