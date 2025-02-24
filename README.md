# Bibliothèque de Liste Chaînée

Ceci est une bibliothèque en C pour gérer des listes chaînées. La bibliothèque fournit des fonctions pour initialiser, insérer, supprimer et afficher des éléments dans une liste chaînée.

## Table des Matières

- [Fonctionnalités](#fonctionnalités)
- [Installation](#installation)
- [Utilisation](#utilisation)
- [Fonctions](#fonctions)
- [Exemple](#exemple)
- [Licence](#licence)

## Fonctionnalités

- Initialiser une liste chaînée.
- Insérer des éléments au début de la liste.
- Insérer des éléments à une position spécifique dans la liste.
- Supprimer le premier élément de la liste.
- Afficher les éléments de la liste.

## Installation

Pour utiliser cette bibliothèque, vous devez inclure le fichier d'en-tête `liste_chainee.h` dans votre projet et lier le fichier source `liste_chainee.c`.

1. Clonez le dépôt :

   ```sh
   git clone https://github.com/votreutilisateur/bibliotheque-liste-chainee.git
   ```

2. Incluez le fichier d'en-tête dans votre projet :

   ```c
   #include "liste_chainee.h"
   ```

3. Utilisez le Makefile pour compiler la bibliothèque et l'exemple :

   ```sh
   make
   ```

   Cela générera la bibliothèque statique `libliste_chainee.a` et l'exemple `example_usage`.

## Utilisation

Pour utiliser la bibliothèque, suivez ces étapes :

1. Initialisez la liste chaînée.
2. Insérez des éléments dans la liste.
3. Affichez la liste.
4. Supprimez des éléments de la liste.
5. Insérez des éléments à une position spécifique.

## Fonctions

### `Liste *initialisation(void)`

Initialise et retourne une nouvelle liste chaînée.

### `int insertion(Liste *liste, int nvNombre)`

Insère un nouvel élément avec la valeur `nvNombre` au début de la liste.

### `int insertion_milieu(Liste *liste, int nvNombre, int position)`

Insère un nouvel élément avec la valeur `nvNombre` à la position spécifiée dans la liste.

### `void suppression(Liste *liste)`

Supprime le premier élément de la liste.

### `void afficher(Liste *liste)`

Affiche les éléments de la liste.

## Exemple

Voici un exemple d'utilisation de la bibliothèque :

```c
#include <stdio.h>
#include <stdlib.h>
#include "liste_chainee.h"

int main(int argc, char *argv[])
{
    Liste *liste = initialisation();

    // Insérer des éléments dans la liste
    printf("Ajout des éléments 10, 15, 22, 55 et 2 à la liste\n");
    insertion(liste, 10);
    insertion(liste, 15);
    insertion(liste, 22);
    insertion(liste, 55);
    insertion(liste, 2);
    afficher(liste);

    // Supprimer le premier élément
    printf("Suppression du premier élément de la liste\n");
    suppression(liste);
    afficher(liste);

    // Insérer un élément à une position spécifique
    printf("Insertion de l'élément 30 en 3ème position en partant de la fin\n");
    insertion_milieu(liste, 30, 3);
    afficher(liste);

    return 0;
}
```

## Licence

Ce projet est sous licence GPL-3.0. Voir le fichier [LICENSE](LICENSE.txt) pour plus de détails.
