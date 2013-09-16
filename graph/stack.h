#ifndef MATTS_STACK
#define MATTS_STACK
// #include "graph.h"

// struct Vertex {
//     int wasVisited;
//     char data[25];
// };

struct Stack {
    int size;
    int position;
    struct Vertex *vertices[];
};

struct Stack *makeStack(int size);
void push(struct Stack *stack, struct Vertex *vertex);
struct Vertex *pop(struct Stack *stack);
struct Vertex *peek(struct Stack *stack);

#endif