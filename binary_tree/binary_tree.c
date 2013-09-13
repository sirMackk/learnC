#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

struct Node *createNode(int value)
{
    struct Node *node = malloc(sizeof(struct Node));
    node->value = value;
    return node;
}

struct Node *insertNode(struct Node *root, struct Node *node)
{
    if(node->value > root->value) {
        if(!root->right) {
            root->right = node;
        } else {
            insertNode(root->right, node);
        }
    } else {
        if(!root->left) {
            root->left = node;
        } else {
            insertNode(root->left, node);
        }
    }
}

void printNode(struct Node *node)
{
    printf("Value: %d\n", node->value);
}

void printNodes(struct Node *root)
{
    //think of a way to print ascii art tree
    printNode(root);
    if(root->left) printNodes(root->left);
    if(root->right) printNodes(root->right);
}