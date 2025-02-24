#ifndef LISTE_H
#define LISTE_H

#define ERREUR_ALLOCATION -1
#define ERREUR_POSITION -2
#define SUCCESS 0

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
int insertion(Liste *liste, int nvNombre);
int insertion_milieu(Liste *liste, int nvNombre, int position);
void suppression(Liste *liste);
void afficher(Liste *Liste);

#endif
