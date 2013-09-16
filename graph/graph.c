#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "graph.h"

struct Vertex *makeVertex(char data[])
{
    struct Vertex *v = malloc(sizeof(struct Vertex));
    v->wasVisited = 0;
    strncpy(v->data, data, 25);
    return v;
}

void zeroGraph(int graph[], int size)
{
    int i;
    for(i = 0; i < size * size; i++) {
        graph[i] = 0;
    }
}

void connectVertices(int graph[], int start, int end)
{
    graph[start * SIZE + end] = 1;
    graph[start + end * SIZE] = 1;
}

void directedConnect(int graph[], int start, int end)
{
    graph[start * SIZE + end] = 1;
}

void printGraph(int graph[], int size)
{
    printf("\n");
    int i, j;
    for(i = 0, j = 1; i < size * size; i++, j++) {
        printf("%d ", graph[i]);
        if(j == 5) {
            printf("\n");
            j = 0;
        }
    }
    printf("\n");
}

void printVertex(struct Vertex *v)
{
    printf("Was visited? %d\n", v->wasVisited);
    printf("Data: %s\n", v->data);
}

void dfs(int graph[], struct Stack *stack)
{
    //push starting point on stack
    //find adjacent point
    //move to adjacent point, mark as visited, push on stack
    //repeat 2
    //if not 2, pop, try 2
}