#include <stdio.h>
#include <stdlib.h>
#include "linked_lists.h"

int main(void)
{
    printf("-> Initialize the list with a 3\n");
    List *list = linked_lists_init(3);

    // insert elements into the list
    printf("-> Adding elements 10, 15, 22, 55 and 2 to the list\n");
    linked_lists_insert(list, 10);
    linked_lists_insert(list, 15);
    linked_lists_insert(list, 22);
    linked_lists_insert(list, 55);
    linked_lists_insert(list, 2);
    linked_lists_display(list);
    printf("Count: %d\n", list->count);

    // deletion of elements
    printf("-> Deleting the two last elements of the list\n");
    linked_lists_remove_last(list);
    linked_lists_remove_last(list);
    linked_lists_display(list);
    printf("Count: %d\n", list->count);

    // insertion in the after
    printf("-> Inserting the element 67 after first element and 30 after 3rd position from the end\n");
    linked_lists_insert_after(list, 67, 0);
    linked_lists_insert_after(list, 30, 2);
    linked_lists_display(list);
    printf("Count: %d\n", list->count);

    printf("-> Free the list\n");
    linked_lists_free(&list);

    return 0;
}
