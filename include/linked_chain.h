/**
 * @file linked_chain.h
 * @brief Library to create and manipulate linked lists.
 * @author Clément Giraud-Sauveur
 * @date 24/02/2025
 */

#ifndef LINKED_CHAIN_H
#define LINKED_CHAIN_H

#define LINKED_CHAIN_ALLOCATION_ERROR -1
#define LINKED_CHAIN_POSITION_ERROR -2
#define LINKED_CHAIN_SUCCESS 0

/**
 * @struct Element
 * @brief Represents an element in the linked list.
 */
typedef struct Element Element;

/**
 * @struct List
 * @brief Represents the linked list.
 */
typedef struct List List;

struct Element
{
    int number;    /**< The value of the element. */
    Element *next; /**< Pointer to the next element in the list. */
};

struct List
{
    Element *first; /**< Pointer to the first element in the list. */
};

/**
 * @brief Initializes a new linked list.
 * @return A pointer to the newly initialized list, or NULL if initialization fails.
 */
List *linked_chain_init(void);

/**
 * @brief Inserts a new element at the beginning of the list.
 * @param list Pointer to the list.
 * @param newNumber The value of the new element.
 * @return LINKED_CHAIN_SUCCESS if successful, LINKED_CHAIN_ALLOCATION_ERROR if memory allocation fails.
 */
int linked_chain_insert(List *list, int newNumber);

/**
 * @brief Inserts a new element at a specified position in the list.
 * @param list Pointer to the list.
 * @param newNumber The value of the new element.
 * @param position The position at which to insert the new element.
 * @return LINKED_CHAIN_SUCCESS if successful, LINKED_CHAIN_ALLOCATION_ERROR if memory allocation fails, LINKED_CHAIN_POSITION_ERROR if the position is invalid.
 */
int linked_chain_insert_middle(List *list, int newNumber, int position);

/**
 * @brief Deletes the first element of the list.
 * @param list Pointer to the list.
 */
void linked_chain_delete(List *list);

/**
 * @brief Prints the elements of the list.
 * @param list Pointer to the list.
 */
void linked_chain_display(List *list);

#endif