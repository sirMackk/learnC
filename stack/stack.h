#ifndef STACK_H
#define STACK_H
#define SIZE 10
#define NL printf("\n");
#define PR(n) printf("%d\n", (n));

void push(int n, int *p);
int pop(int *p);
int *makeStack();
#endif