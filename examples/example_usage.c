#include <stdio.h>
#include <stdlib.h>
#include "linked_chain.h"

int main(void)
{
    List *list = linked_chain_init();

    // insert elements into the list
    printf("Adding elements 10, 15, 22, 55 and 2 to the list\n");
    linked_chain_insert(list, 10);
    linked_chain_insert(list, 15);
    linked_chain_insert(list, 22);
    linked_chain_insert(list, 55);
    linked_chain_insert(list, 2);
    linked_chain_display(list);

    // deletion of elements
    printf("Deleting the first element of the list\n");
    linked_chain_delete(list);
    linked_chain_display(list);

    // insertion in the middle
    printf("Inserting the element 30 in 3rd position from the end\n");
    linked_chain_insert_middle(list, 30, 3);
    linked_chain_display(list);

    return 0;
}
