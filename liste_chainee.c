#include "liste_chainee.h"
#include <stdio.h>
#include <stdlib.h>

Liste *initialisation(void)
{
    Liste *liste = (Liste *)malloc(sizeof(*liste));
    Element *element = (Element *)malloc(sizeof(*element));

    if (liste == NULL || element == NULL)
    {
        free(liste);
        free(element);
        return NULL;
    }

    element->nombre = 0;
    element->suivant = NULL;
    liste->premier = element;

    return liste;
}

int insertion(Liste *liste, int nvNombre)
{
    // Création d'un nouvel élément
    Element *nouveau = (Element *)malloc(sizeof(*nouveau));

    if (liste == NULL || nouveau == NULL)
    {
        free(nouveau);
        return LISTE_CHAINEE_ERREUR_ALLOCATION;
    }
    nouveau->nombre = nvNombre;

    // Insertion de l'élément au début de la liste
    nouveau->suivant = liste->premier;
    liste->premier = nouveau;

    return LISTE_CHAINEE_SUCCESS;
}

int insertion_milieu(Liste *liste, int nvNombre, int position)
{
    // Création d'un nouvel élément
    Element *nouveau = (Element *)malloc(sizeof(*nouveau));

    if (nouveau == NULL)
    {
        return LISTE_CHAINEE_ERREUR_ALLOCATION;
    }

    // Recherche de l'élément auquel ajouter le nouveau après
    Element *element = liste->premier;

    for (int i = 0; i < position; i++)
    {
        if (element->suivant == NULL)
        {
            return LISTE_CHAINEE_ERREUR_POSITION;
        }
    }

    // Insertion du nouvel élément

    return LISTE_CHAINEE_SUCCESS;
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

    Element *actuel = liste->premier;

    while (actuel != NULL)
    {
        printf("%d -> ", actuel->nombre);
        actuel = actuel->suivant;
    }
    printf("NULL\n");
}
