#ifndef LISTE_H
#define LISTE_H

typedef struct Element Element;
struct Element
{
    int nombre;
    Element *suivant;
};

typedef struct Liste Liste;
struct Liste
{
    Element *premier;
};

Liste *initialisation();

void insertion(Liste *liste, int nvNombre);

#endif