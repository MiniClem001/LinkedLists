#include <stdio.h>
#include <stdlib.h>
#include "liste_chainee.h"

int main(int argc, char *argv[])
{
    Liste *liste = initialisation();

    insertion(liste, 10);
    insertion(liste, 15);
    insertion(liste, 2);
    afficher(liste);
    suppression(liste);
    afficher(liste);

    return 0;
}