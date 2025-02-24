#include <stdio.h>
#include <stdlib.h>
#include "liste_chainee.h"

int main(void)
{
    Liste *liste = initialisation();

    // insertion d'elements dans la liste
    printf("Ajout des éléments 10, 15, 22, 55 et 2 à la liste\n");
    insertion(liste, 10);
    insertion(liste, 15);
    insertion(liste, 22);
    insertion(liste, 55);
    insertion(liste, 2);
    afficher(liste);

    // suppression d'elements
    printf("Suppression du premier élément de la liste\n");
    suppression(liste);
    afficher(liste);

    // insertion au milieu
    printf("Insertion de l'élément 30 en 3eme position en partant de la fin\n");
    insertion_milieu(liste, 30, 3);
    afficher(liste);

    return 0;
}
