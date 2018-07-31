#ifndef REGLA_H
#define REGLA_H

#include <QString>
#include <QMetaType>

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

Q_DECLARE_METATYPE(Regla)

#endif // REGLA_H
