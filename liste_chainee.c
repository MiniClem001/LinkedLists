#include "liste_chainee.h"
#include <stdio.h>
#include <stdlib.h>

Liste *initialisation(void)
{
    Liste *liste = (Liste *)malloc(sizeof(*liste));
    Element *element = (Element *)malloc(sizeof(*element));

    if (liste == NULL || element == NULL)
    {
        exit(EXIT_FAILURE);
    }

    element->nombre = 0;
    element->suivant = NULL;
    liste->premier = element;

    return liste;
}

void insertion(Liste *liste, int nvNombre)
{
    // Création d'un nouvel élément
    Element *nouveau = (Element *)malloc(sizeof(*nouveau));
    if (liste == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }
    nouveau->nombre = nvNombre;

    // Insertion de l'élément au début de la liste
    nouveau->suivant = liste->premier;
    liste->premier = nouveau;
}

void insertion_milieu(Liste *liste, int nvNombre, int position)
{
    // Création d'un nouvel élément

    // Recherche de l'élément auquel ajouter le nouveau après

    // Insertion du nouvel élément
}

void suppression(Liste *liste)
{
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    if (liste->premier != NULL)
    {
        Element *aSupprimer = liste->premier;
        liste->premier = aSupprimer->suivant;
        free(aSupprimer);
    }
}

void afficher(Liste *liste)
{
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Element *actuel;
    actuel = liste->premier;

    while (actuel != NULL)
    {
        printf("%d -> ", actuel->nombre);
        actuel = actuel->suivant;
    }
    printf("NULL\n");
}
