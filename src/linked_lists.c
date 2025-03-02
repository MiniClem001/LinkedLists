/**
 * @file linked_lists.c
 * @brief Implementation of the linked list library.
 * @author Clément Giraud-Sauveur
 * @date 2025
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
    list->last = element;

    return list;
}

int linked_lists_insert(List *list, int newNumber)
{
    if (list == NULL)
    {
        return LINKED_LISTS_ALLOCATION_ERROR;
    }
    else if (list->last == NULL)
    {
        return LINKED_LISTS_EMPTY_ERROR;
    }

    // add a new element
    Element *new = (Element *)malloc(sizeof(*new));
    Element *last = list->last;

    if (new == NULL)
    {
        return LINKED_LISTS_ALLOCATION_ERROR;
    }

    new->number = newNumber;
    new->next = NULL;
    last->next = new;
    list->last = new;

    return LINKED_LISTS_SUCCESS;
}

int linked_lists_insert_after(List *list, int newNumber, int position)
{
    // check invalid position
    if (position < 0)
    {
        return LINKED_LISTS_POSITION_ERROR;
    }
    else if (list == NULL)
    {
        return LINKED_LISTS_ALLOCATION_ERROR;
    }

    Element *current = list->first;

    for (int i = 0; i < position; i++)
    {
        if (current->next == NULL)
        {
            return LINKED_LISTS_POSITION_ERROR;
        }
        current = current->next;
    }

    Element *new = (Element *)malloc(sizeof(*new));

    if (new == NULL)
    {
        return LINKED_LISTS_ALLOCATION_ERROR;
    }

    new->number = newNumber;
    new->next = current->next;
    current->next = new;
    if (new->next == NULL)
    {
        list->last = new;
    }

    return LINKED_LISTS_SUCCESS;
}

int linked_lists_remove_last(List *list)
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

    // free current if last item && set list->first to NULL
    if (current->next == NULL)
    {
        list->first = NULL;
        list->last = NULL;
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
    list->last = previous;
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

    (*list)->first = NULL;
    (*list)->last = NULL;

    free(*list);
    *list = NULL;

    return LINKED_LISTS_SUCCESS;
}

int linked_lists_display(List *list)
{
    if (list == NULL)
    {
        return LINKED_LISTS_ALLOCATION_ERROR;
    }

    Element *current = list->first;

    while (current != NULL)
    {
        printf("%d -> ", current->number);
        current = current->next;
    }
    printf("NULL\n");

    return LINKED_LISTS_SUCCESS;
}
