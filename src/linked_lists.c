/**
 * @file linked_lists.c
 * @brief Implementation of the linked list library.
 * @author Clément Giraud-Sauveur
 * @date 24/02/2025
 */

#include "linked_lists.h"
#include <stdio.h>
#include <stdlib.h>

List *linked_lists_init(int number)
{
    List *list = (List *)malloc(sizeof(*list));
    Element *element = (Element *)malloc(sizeof(*element));

    if (list == NULL || element == NULL)
    {
        free(list);
        free(element);
        return NULL;
    }

    element->number = number;
    element->next = NULL;
    list->first = element;

    return list;
}

int linked_lists_insert(List *list, int newNumber)
{
    if (list == NULL)
    {
        return LINKED_LISTS_ALLOCATION_ERROR;
    }

    // find last element of the list
    Element *last = list->first;

    while (last->next != NULL)
    {
        last = last->next;
    }

    // add a new element
    Element *new = (Element *)malloc(sizeof(*new));

    new->number = newNumber;
    new->next = NULL;
    last->next = new;

    return LINKED_LISTS_SUCCESS;
}

int linked_lists_insert_middle(List *list, int newNumber, int position)
{
    if (position < 0)
    {
        return LINKED_LISTS_POSITION_ERROR;
    }

    Element *current = list->first;
    Element *previous = NULL;

    for (int i = 0; i < position; i++)
    {
        if (current->next == NULL)
        {
            return LINKED_LISTS_POSITION_ERROR;
        }
        previous = current;
        current = current->next;
    }

    Element *new = (Element *)malloc(sizeof(*new));

    if (new == NULL)
    {
        return LINKED_LISTS_ALLOCATION_ERROR;
    }

    new->number = newNumber;

    previous->next = new;
    new->next = current;

    return LINKED_LISTS_SUCCESS;
}

int linked_lists_remove(List *list)
{
    if (list == NULL)
    {
        return LINKED_LISTS_ALLOCATION_ERROR;
    }

    if (list->first == NULL)
    {
        return LINKED_LISTS_EMPTY_ERROR;
    }

    Element *current = list->first;
    Element *previous = NULL;

    // free current is last last item && set list->first to NULL
    if (current->next == NULL)
    {
        list->first = NULL;
        free(current);

        return LINKED_LISTS_SUCCESS;
    }

    // find last element of the list and free it
    while (current->next != NULL)
    {
        previous = current;
        current = current->next;
    }

    previous->next = NULL;
    free(current);

    return LINKED_LISTS_SUCCESS;
}

int linked_lists_free(List **list)
{
    if (list == NULL || *list == NULL)
    {
        return LINKED_LISTS_ALLOCATION_ERROR;
    }

    Element *current = (*list)->first;
    Element *next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }

    free(*list);
    *list = NULL;

    return LINKED_LISTS_SUCCESS;
}

void linked_lists_display(List *list)
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
