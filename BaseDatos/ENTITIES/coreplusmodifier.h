#ifndef COREPLUSMODIFIER_H
#define COREPLUSMODIFIER_H

#include <QString>

class Coreplusmodifier
{
public:
    Coreplusmodifier();

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

#endif // COREPLUSMODIFIER_H
