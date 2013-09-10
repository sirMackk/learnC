#ifndef STACK_H
#define STACK_H
#define SIZE 10
#define NL printf("\n");
#define PR(n) printf("[%d] ", (n));

struct Stack {
    int n[SIZE];
    int position;
};

void push(struct Stack *stack, int n);
int pop(struct Stack *stack);
struct Stack *makeStack();
void printStack(struct Stack *stack);

#endif