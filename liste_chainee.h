#ifndef LISTE_H
#define LISTE_H

typedef struct Element Element;
typedef struct Liste Liste;

struct Element
{
    int nombre;
    Element *suivant;
};

struct Liste
{
    Element *premier;
};

Liste *initialisation(void);
void insertion(Liste *liste, int nvNombre);
void insertion_milieu(Liste *liste, int nvNombre, int position);
void suppression(Liste *liste);
void afficher(Liste *Liste);

#endif
