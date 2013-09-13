#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

int main(void)
{
    struct Node *root = createNode(10);
    // printNode(root);

    insertNode(root, createNode(12));
    insertNode(root, createNode(5));

    insertNode(root, createNode(11));
    insertNode(root, createNode(20));

    insertNode(root, createNode(7));

    printNodes(root);
}