#include <stdio.h>
#include <stdlib.h>
#include "vertex_stack.h"
#include "graph.h"

struct Stack *makeVStack(int size)
{   
    //allocate a chunk of memory the size of
    //n vertices + 2 struct Stack ints
    struct Vertex *dd;

    // struct Stack *stack = malloc(sizeof(struct Vertex *) * size + sizeof(int) * 2);
    struct vStack *stack = malloc(sizeof(dd) * SIZE);

    stack->size = size;
    stack->position = 0;

    return stack;
}

void vpush(struct vStack *stack, struct Vertex *vertex)
{
    //consider a full stack
    stack->vertices[stack->position++] = vertex;
}

struct Vertex *vpop(struct vStack *stack)
{
    return stack->vertices[--stack->position];
}

struct Vertex *vpeek(struct vStack *stack)
{
    return stack->vertices[stack->position - 1];
}

int isVEmpty(struct vStack *stack)
{
    if(stack->position == 0)
        return 1;
    else
        return 0;
}