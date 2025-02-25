/**
 * @file linked_chain.c
 * @brief Implementation of the linked list library.
 * @author Clément Giraud-Sauveur
 * @date 24/02/2025
 */

#include "linked_chain.h"
#include <stdio.h>
#include <stdlib.h>

List *linked_chain_init(void)
{
    List *list = (List *)malloc(sizeof(*list));
    Element *element = (Element *)malloc(sizeof(*element));

    if (list == NULL || element == NULL)
    {
        free(list);
        free(element);
        return NULL;
    }

    element->number = 0;
    element->next = NULL;
    list->first = element;

    return list;
}

int linked_chain_insert(List *list, int newNumber)
{
    Element *new = (Element *)malloc(sizeof(*new));

    if (list == NULL || new == NULL)
    {
        free(new);
        return LINKED_CHAIN_ALLOCATION_ERROR;
    }
    new->number = newNumber;

    new->next = list->first;
    list->first = new;
    return LINKED_CHAIN_SUCCESS;
}

int linked_chain_insert_middle(List *list, int newNumber, int position)
{
    if (position < 0)
    {
        return LINKED_CHAIN_POSITION_ERROR;
    }

    Element *current = list->first;
    Element *previous = NULL;

    for (int i = 0; i < position; i++)
    {
        if (current->next == NULL)
        {
            return LINKED_CHAIN_POSITION_ERROR;
        }
        previous = current;
        current = current->next;
    }

    Element *new = (Element *)malloc(sizeof(*new));

    if (new == NULL)
    {
        return LINKED_CHAIN_ALLOCATION_ERROR;
    }

    new->number = newNumber;

    previous->next = new;
    new->next = current;

    return LINKED_CHAIN_SUCCESS;
}

void linked_chain_delete(List *list)
{
    if (list == NULL)
    {
        exit(EXIT_FAILURE);
    }

    if (list->first != NULL)
    {
        Element *toDelete = list->first;
        list->first = toDelete->next;
        free(toDelete);
    }
}

void linked_chain_display(List *list)
{
    if (list == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Element *current = list->first;

    while (current != NULL)
    {
        printf("%d -> ", current->number);
        current = current->next;
    }
    printf("NULL\n");
}
