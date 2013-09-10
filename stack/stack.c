#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct Stack *makeStack()
{
    //redo this to use typedef
    struct Stack *stack = malloc(sizeof(struct Stack));
    int i;
    for(i = 0; i < SIZE; i++) {
        stack->n[i] = -1;
    }
    stack->position = 0;

    return stack;
}

int pop(struct Stack *stack)
{   
    if(!isEmpty(stack)) {
       int i = stack->n[--stack->position];
        stack->n[stack->position] = -1;
        return i; 
    } else {
        printf("Error: stack is empty!\n");
        exit(0);
    }

}

void push(struct Stack *stack, int n)
{
    if(!isFull(stack)) {
        stack->n[stack->position++] = n;
    } else {
        printf("Error: stack is full!\n");
        exit(0);
    }
}

void printStack(struct Stack *stack)
{
    int i;
    for(i = 0; i < SIZE; i++) {
        PR(stack->n[i]);
    }
    NL
}

int isFull(struct Stack *stack)
{
    return stack->position == 10 ? 1 : 0;
}

int isEmpty(struct Stack *stack)
{
    return stack->position != 0 ? 0 : 1;
}