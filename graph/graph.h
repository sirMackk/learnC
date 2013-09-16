#ifndef MATTS_GRAPH
#define MATTS_GRAPH
#define SIZE 5

#define PRN(a) printf("%d\n", (a));

// #include "stack.h"
struct Vertex {
    int wasVisited;
    char data[25];
};

void connectVertices(int graph[], int start, int end);
void directedConnect(int graph[], int start, int end);
void printGraph(int graph[], int size);

void dfs(int graph[], struct Stack *stack);
#endif