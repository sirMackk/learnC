#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

int main(void)
{
    // CREATE_NODE(int, f)
    struct Node *first = createNodeString(3, "cat");
    struct Node *second = createNodeString(4, "dog");
    struct Node *third = createNodeString(4, "ARMY");

    // struct Node *first = create_int_Node(intNode, 5);
    // struct Node *second = create_int_Node(intNode, 15);
    first->next = second;
    second->next = third;

    printNodes(first);

    return 0;
}