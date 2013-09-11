#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"

#define CREATE_NODE(ntype, stype)                                   \
struct Node *create_ntype##Node(enum node_type type, ntype value)   \
{                                                                   \
    struct Node *node;                                              \
    node->type = type;                                              \
    node->u->stype##->value;                                        \
    node->next = NULL;                                              \
    return node;                                                    \
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

struct Node *createNodeString(int size, char item[])
{
    //this could take first node as optional argument
    // if null then its first, if not then set next in prev to cur
    struct Node *node = malloc(NODE_TYPE_SIZE + INT_SIZE + 
                        NODE_POINTER_SIZE + (CHAR_SIZE * size));
    printf("%s\n", item);
    node->type = stringNode;
    strncpy(node->c, item, size);
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

// struct Node *searchNode(int id)
// {

// }