#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "graph.h"

struct Stack *makeStack(int size)
{   
    //allocate a chunk of memory the size of
    //n vertices + 2 struct Stack ints
    struct Vertex *dd;

    // struct Stack *stack = malloc(sizeof(struct Vertex *) * size + sizeof(int) * 2);
    struct Stack *stack = malloc(sizeof(dd) * SIZE);

    stack->size = size;
    stack->position = 0;

    return stack;
}

void push(struct Stack *stack, struct Vertex *vertex)
{
    //consider a full stack
    stack->vertices[stack->position++] = vertex;
}

struct Vertex *pop(struct Stack *stack)
{
    return stack->vertices[--stack->position];
}

struct Vertex *peek(struct Stack *stack)
{
    return stack->vertices[stack->position - 1];
}