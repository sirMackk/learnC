#include <stdlib.h>
#include "stack.h"

struct Stack *makeStack(int size)
{
    struct Stack *stack = calloc(sizeof(int), size);
    stack->size = size;
    stack->position = 0;

    return stack;
}

void push(struct Stack *stack, int value)
{
    stack->stack[stack->position++] = value;
}

int pop(struct Stack *stack)
{
    return stack->stack[--stack->position];
}

int peek(struct Stack *stack)
{
    return stack->stack[stack->position - 1];
}

int isEmpty(struct Stack *stack)
{
    if(stack->position == -1)
        return 1;
    else
        return 0;
}