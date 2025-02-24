/**
 * @file Liste_chainee.h
 * @brief Library to create and manipulate linked lists.
 * @author Clément Giraud-Sauveur
 * @date 24/02/2025
 */

#ifndef LISTE_CHAINEE_H
#define LISTE_CHAINEE_H

#define LISTE_CHAINEE_ERREUR_ALLOCATION -1
#define LISTE_CHAINEE_ERREUR_POSITION -2
#define LISTE_CHAINEE_SUCCESS 0

/**
 * @struct Element
 * @brief Represents an element in the linked list.
 */
typedef struct Element Element;

/**
 * @struct Liste
 * @brief Represents the linked list.
 */
typedef struct Liste Liste;

struct Element
{
    int nombre;       /**< The value of the element. */
    Element *suivant; /**< Pointer to the next element in the list. */
};

struct Liste
{
    Element *premier; /**< Pointer to the first element in the list. */
};

/**
 * @brief Initializes a new linked list.
 * @return A pointer to the newly initialized list, or NULL if initialization fails.
 */
Liste *initialisation(void);

/**
 * @brief Inserts a new element at the beginning of the list.
 * @param liste Pointer to the list.
 * @param nvNombre The value of the new element.
 * @return LISTE_CHAINEE_SUCCESS if successful, LISTE_CHAINEE_ERREUR_ALLOCATION if memory allocation fails.
 */
int insertion(Liste *liste, int nvNombre);

/**
 * @brief Inserts a new element at a specified position in the list.
 * @param liste Pointer to the list.
 * @param nvNombre The value of the new element.
 * @param position The position at which to insert the new element.
 * @return LISTE_CHAINEE_SUCCESS if successful, LISTE_CHAINEE_ERREUR_ALLOCATION if memory allocation fails, LISTE_CHAINEE_ERREUR_POSITION if the position is invalid.
 */
int insertion_milieu(Liste *liste, int nvNombre, int position);

/**
 * @brief Deletes the first element of the list.
 * @param liste Pointer to the list.
 */
void suppression(Liste *liste);

/**
 * @brief Prints the elements of the list.
 * @param liste Pointer to the list.
 */
void afficher(Liste *liste);

#endif