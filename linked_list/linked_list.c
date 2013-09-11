#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

#define CREATE_NODE(ntype, stype)                                   \
struct Node *createntype##Node(enum node_type type, ntype value)    \
{                                                                   \
    struct Node *node;
    node->type = type;
    node->u->stype##->value;
    node->next = NULL;
}

// struct Node *createNode(enum node_type type)
// {
//     struct Node *node = malloc(NODE_TYPE_SIZE + INT_SIZE + NODE_POINTER_SIZE);
//     struct Node *node;

//     node->type = type;
//     switch(type) {
//         case intNode:
//             node->u->i = 
//     }

// }

struct Node *createNodeString(int size)
{
    struct Node *node = malloc(NODE_TYPE_SIZE + INT_SIZE + 
                        NODE_POINTER_SIZE + (CHAR_SIZE * size));
}

int destroyNode(struct Node *node)
{

}

void printNodes(struct Node *first)
{

}

struct Node *searchNode(int id)
{

}