#include <stdio.h>
#include "stack.h"

int main(int argc, char *argv[])
{
    int *stack = makeStack();
    int i = 0;

    NL
    printf("%p\n", stack);
    push(5, stack++);
    printf("%p\n", stack);
    push(15, stack++);
    printf("%p\n", stack);

    int j, k;
    k = pop(--stack);
    j = pop(--stack);
    PR(k)
    PR(j)

    push(12, stack++);
    push(24, stack++);
    k = pop(--stack);
    j = pop(--stack);
    PR(k)
    PR(j)


    for(i = 0; i < SIZE; i++) {
        printf("[%d] ", stack[i]);
    }
    NL

    return 0;
}