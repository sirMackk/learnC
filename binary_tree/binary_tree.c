#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

//mhmmmmmm, recursion..

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

int printNode(struct Node *node)
{
    if(!node) {
        fprintf(stderr, "Not found\n");
        return 0;
    }
    printf("Value: %d\n", node->value);
}

void printNodes(struct Node *root)
{
    //think of a way to print ascii art tree
    printNode(root);
    if(root->left) printNodes(root->left);
    if(root->right) printNodes(root->right);

}

struct Node *searchNode(struct Node *root, int value)
{
    printf("searching %d...\n", root->value);
    if(root->value == value) {
        printf("Found!: ");
        return root;
    }
    if(value > root->value && root->right) {
        return searchNode(root->right, value);
    } else if(root->left) {
        return searchNode(root->left, value);
    } else {
        return NULL;
    }

}

struct Node *deleteNodeWrapper(struct Node *root, int value, struct Node *prev)
{
    //this wrapper was added on to take care of the
    //delete-the-root-with-one-child case
    struct Node *tmp = deleteNode(root, value, prev);
    if(tmp)
        return tmp;
    else
        return root;
}

struct Node *deleteNode(struct Node *root, int value, struct Node *prev)
{
    int delete = 1;
    //traversing
    if(value > root->value) {
        return deleteNode(root->right, value, root);
    } else if(value < root->value) {
        return deleteNode(root->left, value, root);
    } else if(value == root->value) {
        printf("found node to delete! %d\n", root->value);

        //deletion
        //root node w/o children or node without children
        if(!root->left && !root->right) {
            if(!prev)
                printf("deleting root...\n");
            else if(prev->value > value) {
                prev->left = NULL;
            } else {
                prev->right = NULL;
            }
        //node has one child
        } else if(!root->right) {
            //if it's root, replace root with left child
            if(!prev) {
                free(root);
                root = root->left;
                delete = 0;

            //but if its smaller than parent, attach left to left parent
            } else if(prev->value > value) {
                prev->left = root->left;
            } else {
            //if bigger, attach left to right parent
                prev->right = root->left;
            }
        } else if(!root->left) {
            if(!prev) {
                free(root);
                root = root->right;
                delete = 0;
            } else if(prev->value > value) {
                prev->left = root->right;
            } else {
                prev->right = root->right;
            }
        //node has two children
        } else {
            struct Node *successor = findSuccessor(root->right);
            //if successor is right child of node to be deleted:
            if(successor == root->right) {
                //move left child of deleted node to successor left
                successor->left = root->left;
                //move successor to parent:
                if(prev->value > value) {
                    prev->left = successor;
                } else {
                    prev->right = successor;
                }
            //if successor is some left descendent of node to be deleted
            } else {
                //if success has right child, attach it to its parent
                if(successor->right) {
                    struct Node *successorParent = findSuccessorParent(root->right);
                    successorParent->left = successor->right;
                }
                //move deleted node's children to successor
                successor->right = root->right;
                successor->left = root->left;
                //attach successor to parent
                if(prev->value > value) {
                    prev->left = successor;
                } else {
                    prev->right = successor;
                }
            }
        }
        //finally delete the node after all node shifts
        if(delete)
        {
            free(root);
            return NULL;
        } else {
            return root;
        }
    } else {
        //not found, return null pointer
        return NULL;
    }
}

//find successor of node, always pass in right child
//of node to be deleted as *node
struct Node *findSuccessor(struct Node *node)
{
    if(node->left)
        return findSuccessor(node->left);
    else
        return node;
}

//find parent of successor, gotta find a way to maybe
//combine these two successor fns into one
struct Node *findSuccessorParent(struct Node *node)
{
    if(!node->left->left)
        return node;
    else
        findSuccessorParent(node);
}



//This search fn works same as above, except it takes note of 
//previous nodes. Used for deletion to relink nodes one node apart
struct Node *searchPrevNode(struct Node *root, int value, struct Node* prev)
{
    if(root->value == value) return root;

    if(value > root->value && root->right) {
        return searchPrevNode(root->right, value, root);
    } else if(root->left) {
        return searchPrevNode(root->left, value, root);
    } else {
        return NULL;
    }
}