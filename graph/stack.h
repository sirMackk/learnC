#ifndef MATTS_STACK
#define MATTS_STACK

struct Stack {
    int position;
    int size;
    int stack[];
};

struct Stack *makeStack(int size);
void push(struct Stack *stack, int value);
int pop(struct Stack *stack);
int peek(struct Stack *stack);
int isEmpty(struct Stack *stack);

#endif