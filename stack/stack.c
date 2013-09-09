#include <stdio.h>
#include "stack.h"

int *makeStack()
{
    int stack[SIZE];
    int *p = stack;

    //can't erase the memory of this array outside of function

    return p;
}

int pop(int *p)
{
    return *p;
}

void push(int n, int *p)
{
    *p = n;
}