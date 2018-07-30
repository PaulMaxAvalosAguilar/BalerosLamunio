#ifndef COREPLUSMODIFIERS_H
#define COREPLUSMODIFIERS_H

#include <QString>

class Coreplusmodifiers
{
public:
    Coreplusmodifiers();

    int getId() const;
    void setId(int value);

    QString getFullNombre() const;
    void setFullNombre(const QString &value);

    int getCoreBearing_ID() const;
    void setCoreBearing_ID(int value);

private:
    int id;
    QString fullNombre;
    int coreBearing_ID;

};

#endif // COREPLUSMODIFIERS_H
