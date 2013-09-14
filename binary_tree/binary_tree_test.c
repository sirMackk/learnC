#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

int main(void)
{

    //easier case when deleting node with one child
    struct Node *root = createNode(10);

    insertNode(root, createNode(12));
    insertNode(root, createNode(5));

    insertNode(root, createNode(11));
    insertNode(root, createNode(20));

    insertNode(root, createNode(7));

    printNodes(root);

    printNode(searchNode(root, 11));

    deleteNode(root, 5, NULL);
    printf("\n");
    printNodes(root);
    printf("\n");

    //complicated case of deleted a node with two children

    root = createNode(50);

    insertNode(root, createNode(75));
    insertNode(root, createNode(62));
    insertNode(root, createNode(87));
    insertNode(root, createNode(77));
    insertNode(root, createNode(79));
    insertNode(root, createNode(93));

    printNodes(root);

    deleteNode(root, 75, NULL);
    printf("\n");
    printNodes(root);

}