#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"

struct Node *createNode(struct Node *(*allocateMem)(), int size)
{
    struct Node *node = (*allocateMem)(size);
    node->next = NULL;
    return node;
}

int destroyNode(struct Node *node)
{
    //this should link prev node to next node and delete current node
    if(node->type == stringNode) free(node->c);
    free(node);
    return 0;
    // if(free(node)) {
    //     return 0;
    // } else {
    //     return 1;
    // }

}

void printNodes(struct Node *first)
{
    struct Node *node = first;
    // while(node->next) { //make loop without break, but this omits
    // last item in list
    while(1) {
        switch(node->type) {
            case intNode:
                printf("Value: %d\n", node->u.i);
                break;
            case floatNode:
                printf("Value: %f\n", node->u.f);
                break;
            case stringNode:
                printf("Value: %s\n", node->c);
                break;
        }
        if(!node->next) break;
        node = node->next;
    }
}

struct Node *allocateLinkMem(int size)
{
    return malloc(NODE_TYPE_SIZE + INT_SIZE + 
                    NODE_POINTER_SIZE + size);
}

// struct Node *searchNode(int id)
// {

// }