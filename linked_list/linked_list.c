#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"

//ensure fns that accepts nodes arent getting nulls

struct Node *createNode(int size, enum node_type type)
{
    int i = 0;
    if(type == stringNode) i = CHAR_SIZE;
    struct Node *node = malloc(NODE_TYPE_SIZE + INT_SIZE + 
                    NODE_POINTER_SIZE + size + i);
    if(type == stringNode) node->c[size] = '\0'; //add null byte to end of string
    node->next = NULL;
    return node;
}

struct Node *insertNode(struct Node *first, struct Node *node)
{
    struct Node *prev;
    do {
        //so ugly
        //make case when inserting link smaller than first node
        if(node->type == intNode) {
            //in case insertion is at the end of the list
            if(!first->next && node->u.i > first->u.i) {
                first->next = node;
                break;
            //in case insertion is in the middle of the list  
            } else if(node->u.i > prev->u.i && node->u.i < first->u.i) {
                    prev->next = node;
                    node->next = first;
                    break;
            }
        }
        prev = first;
    } while(first = first->next);
}

int destroyNode(struct Node *first, struct Node *node)
{
    if(!node) return 0;
    struct Node *prev;
    do {
        
        if(first->next == node) {
            prev = first;
            break;
        }
    } while(first = first->next);
    if(prev) {
        prev->next = node->next;
        free(node);
        return 1;
    } else {
        return 0;
    }
}

void printNodes(struct Node *node)
{
    do {
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
    } while(node = node->next);
}

void printNode(struct Node *node)
{
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
}

struct Node *searchIntNode(struct Node *node, int n)
{
    do {
        if(node->u.i == n) return node;
    } while(node = node->next);
    return NULL;
}

struct Node *searchFloatNode(struct Node *node, float n)
{
    do {
        if(node->u.f == n) return node;
    } while(node = node->next);
    return NULL;
}

struct Node *searchStringNode(struct Node *node, char *n)
{
    do {
        if(strcmp(node->c, n) == 0) return node;
    } while(node = node->next);
    return NULL;
}