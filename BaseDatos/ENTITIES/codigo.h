#ifndef CODIGO_H
#define CODIGO_H

#include <QString>
#include <QMetaType>

class Codigo
{
public:
    Codigo();

    int getId() const;
    void setId(int value);

    QString getCaracteres() const;
    void setCaracteres(const QString &value);

    int getSubcategoria_ID() const;
    void setSubcategoria_ID(int value);

private:
    int id;
    QString caracteres;
    int subcategoria_ID;

};

Q_DECLARE_METATYPE(Codigo)

#endif // CODIGO_H
