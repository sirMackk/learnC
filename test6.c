#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 10
#define NL printf("\n");

void push(int *stack, int n)
{
    *(stack++) = n;
}

int pop(int *stack)
{
    return *(stack--);
}

struct Person {
    char name[25];
    int id;
    int date;
};

enum Direction {SOUTH, NORTH, EAST, WEST};


void printBob(struct Person *beb)
{
    NL
    printf("name: %s\n", beb->name);
}


int main(int argc, char *argv[])
{
    // int stack[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int stack[MAX];
    int *p = stack;
    // printf("%d\n", *p);

    int i;
    for(i = 0; i < MAX; i++){
        stack[i] = -1;
    }

    for(i = 0; i < sizeof(stack)/sizeof(int); i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");

    push(p, 10);

    for(i = 0; i < sizeof(stack)/sizeof(int); i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");

    printf("%d\n", pop(p));

    for(i = 0; i < sizeof(stack)/sizeof(int); i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");

    push(p, 112);
    push(p, 56);

    for(i = 0; i < sizeof(stack)/sizeof(int); i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");


    // for(; *p == -1; p++){
    //     printf("%d\n", *p);
    // }


    enum Direction d1 = EAST;

    switch(d1) {
        case SOUTH:
            printf("SOUTH");
            break;
        case NORTH:
            printf("NORTH");
            break;
        case EAST:
            printf("EAST");
            break;
        case WEST:
            printf("WEST");
            break;
        default:
            printf("Default");
            break;
    }
    NL



    struct Person bob = { .name = "Bob", .id = 1, .date = 2101990 };
    printf("Name: %s\nid: %d\ndate:%d\n", bob.name, bob.id, bob.date);
    NL
    struct Person *joe = malloc(sizeof(struct Person));
    strcpy(joe->name, "Joe");
    joe->id = 2;
    joe->date = 1105991;
    printf("Name: %s\nid: %d\ndate:%d\n", joe->name, joe->id, joe->date);

    printBob(joe);

    struct Person *bb = &bob;
        printBob(bb);



    return 0;
}