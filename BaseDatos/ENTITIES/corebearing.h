#ifndef COREBEARING_H
#define COREBEARING_H

#include <QString>

class Corebearing
{
public:
    Corebearing();

    int getId() const;
    void setId(int value);

    QString getCoreValue() const;
    void setCoreValue(const QString &value);

    int getDiamInterno() const;
    void setDiamInterno(int value);

    int getDiamExterno() const;
    void setDiamExterno(int value);

    int getEspesura() const;
    void setEspesura(int value);

    int getRegla_ID() const;
    void setRegla_ID(int value);

private:
    int id;
    QString coreValue;
    int diamInterno;
    int diamExterno;
    int espesura;
    int regla_ID;
};

#endif // COREBEARING_H
