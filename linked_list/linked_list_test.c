#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"

int main(void)
{
    struct Node *first = createNode(allocateLinkMem, (CHAR_SIZE * 3));
    first->type = stringNode;
    strncpy(first->c, "cat", (CHAR_SIZE * 3));

    struct Node *second = createNode(allocateLinkMem, (CHAR_SIZE * 3));
    second->type = stringNode;
    strncpy(second->c, "dog", (CHAR_SIZE * 3));
    first->next = second;

    struct Node *third = createNode(allocateLinkMem, INT_SIZE);
    third->type = intNode;
    third->u.i = 15;
    second->next = third;

    struct Node *fourth = createNode(allocateLinkMem, FLOAT_SIZE);
    fourth->type = floatNode;
    fourth->u.f = 12.3f;
    third->next = fourth;

    struct Node *fifth = createNode(allocateLinkMem, (CHAR_SIZE * 4));
    fifth->type = stringNode;
    strncpy(fifth->c, "army", (CHAR_SIZE * 4));
    fourth->next = fifth;

    printNodes(first);

    return 0;
}

