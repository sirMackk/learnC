#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "graph.h"
#include "queue.h"

//TODO: 
// - add safety features to stacks and queues
// - make it accept user input or machine readable input (json/xml)
// - make size variable, test out with huge graphs
// - add and test directed graphs and topo search
// - add weights to graphs
// - hmm, how about writing graph to file?
// - python gui interface hmmm?

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
    printf("Data: %s\n", v->data);
}

void dfs(int graph[], struct Vertex *vertexList[])
{
    printf("Starting dfs:\n");
    struct Stack *stack = makeStack(SIZE);
    int v;

    vertexList[0]->wasVisited = 1;
    push(stack, 0);
    printVertex(vertexList[0]);
    
    while(!isEmpty(stack)) {
        v = getAdjacentVertex(graph, vertexList, peek(stack));
        if(v == -1) {
            pop(stack);
        } else {
            vertexList[v]->wasVisited = 1;
            printVertex(vertexList[v]);
            push(stack, v);
        }
    }
    resetVisitedFlags(vertexList, SIZE);
}

void bfs(int graph[], struct Vertex *vertexList[])
{
    printf("Starting bfs:\n");
    struct Queue *q = makeQueue(SIZE);
    vertexList[0]->wasVisited = 1;
    qpush(q, 0);
    printVertex(vertexList[0]);
    int v1, v2;

    while(!isQEmpty(q)) {
        v1 = qpop(q);
        while((v2 = getAdjacentVertex(graph, vertexList, v1)) != -1) {
            vertexList[v2]->wasVisited = 1;
            printVertex(vertexList[v2]);
            qpush(q, v2);
        }

    }
    resetVisitedFlags(vertexList, SIZE);
}

int getAdjacentVertex(int graph[], struct Vertex *vertexList[], int row)
{
    int i;
    for(i = row * SIZE; i < (row * SIZE) + SIZE; i++) {
        if(graph[i] == 1 && vertexList[i % SIZE]->wasVisited != 1) {
            return i % SIZE;
        }
    }
    return -1;
}

void resetVisitedFlags(struct Vertex *vertexList[], int size)
{
    int i;
    for(i = 0; i < size; i++) {
        vertexList[i]->wasVisited = 0;
    }
    printf("\n");
}