#include <stdio.h>
#include <stdlib.h>
#include "linked_lists.h"

int main(void)
{
    List *list = linked_lists_init(3);

    // insert elements into the list
    printf("Adding elements 10, 15, 22, 55 and 2 to the list\n");
    linked_lists_insert(list, 10);
    linked_lists_insert(list, 15);
    linked_lists_insert(list, 22);
    linked_lists_insert(list, 55);
    linked_lists_insert(list, 2);
    linked_lists_display(list);

    // deletion of elements
    printf("Deleting the last element of the list\n");
    linked_lists_remove(list);
    linked_lists_display(list);

    // insertion in the middle
    printf("Inserting the element 30 in 3rd position from the end\n");
    linked_lists_insert_middle(list, 30, 3);
    linked_lists_display(list);

    printf("Free the list");
    linked_lists_free(list);

    return 0;
}
