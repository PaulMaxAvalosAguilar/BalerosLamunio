#ifndef CLASIFICACION_H
#define CLASIFICACION_H


class Clasificacion
{
public:
    Clasificacion();

    int getId() const;
    void setId(int value);

    int getSubcategoria_ID() const;
    void setSubcategoria_ID(int value);

    int getCoreplusmodifier_ID() const;
    void setCoreplusmodifier_ID(int value);

private:
    int id;
    int subcategoria_ID;
    int coreplusmodifier_ID;
};

#endif // CLASIFICACION_H
