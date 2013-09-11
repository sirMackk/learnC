#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(int argc, char *argv[])
{
    printf("How big do you want the stack to be?\n");
    int stackSize;
    scanf("%d", &stackSize);
    struct Stack *stack = makeStack(stackSize);
    char choice;
    int item;

    while(1) {

        printf("i to insert, x to exit, p to pop, r to print, c to clear\n");
        scanf("%c", &choice);
        //error here as scanf reads the newline char
        if(choice == '\n') continue;
        switch(choice) {
            case 'i':
                printf("Type an integer to insert into the stack: \n");
                scanf("%d", &item);
                push(stack, (int)item);
                printf("Inserted %d!\n", item);
                break;
            case 'p':
                printf("Popping: %d\n", pop(stack));
                break;
            case 'x':
                printf("Bye\n");
                free(stack);
                return 0;
            case 'r':
                printStack(stack);
                break;
            case 'c':
                free(stack);
                struct Stack *stack = makeStack(stackSize);
            default:
                printf("Wrong option!\n");
        }
    }
    return 0;
}