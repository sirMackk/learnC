#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"

int main(void)
{
    struct Node *first = createNode((CHAR_SIZE * 3), stringNode);
    first->type = stringNode;
    strncpy(first->c, "cat", (CHAR_SIZE * 3));

    struct Node *second = createNode((CHAR_SIZE * 3), stringNode);
    second->type = stringNode;
    strncpy(second->c, "dog", (CHAR_SIZE * 3));
    first->next = second;

    struct Node *third = createNode(INT_SIZE, intNode);
    third->type = intNode;
    third->u.i = 15;
    second->next = third;

    struct Node *fourth = createNode(FLOAT_SIZE, intNode);
    fourth->type = floatNode;
    fourth->u.f = 12.3f;
    third->next = fourth;

    struct Node *fifth = createNode((CHAR_SIZE * 4), stringNode);
    fifth->type = stringNode;
    strncpy(fifth->c, "boyd", (CHAR_SIZE * 4));
    fourth->next = fifth;

    printNodes(first);
    printf("\n");
    struct Node *found;
    if(found = searchStringNode(first, "dog")) {
        printNode(found);
    } else {
        printf("node not found!\n");
    }

    destroyNode(first, searchStringNode(first, "dog"));
    printf("more nodes:\n");
    printNodes(first);
    destroyNode(first, searchFloatNode(first, 12.4f));
    printNodes(first);

    return 0;
}

