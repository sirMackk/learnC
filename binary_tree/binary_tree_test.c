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

    //weird error where it will segfault
    //when root has left child
    //funny, because it segfaults in #2 or #3
    //I think I should be using free() between these
    //tests..
    // insertNode(root, createNode(7));

    printNodes(root);

    printNode(searchNode(root, 11));

    root = deleteNodeWrapper(root, 5, NULL);
    printf("\n");
    printNodes(root);
    printf("\n");


    //case where we're deleting the root node with 1 child
    root = createNode(50);
    insertNode(root, createNode(25));
    root = deleteNode(root, 50, NULL);
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
    root = deleteNodeWrapper(root, 75, NULL);
    // printf("%p", root, root->value);
    // printf("\n");
    printNodes(root);

}