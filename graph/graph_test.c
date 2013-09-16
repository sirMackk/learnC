#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "stack.h"


int main(void)
{
    //adjacency matrix
    int graph[SIZE][SIZE];
    zeroGraph(*graph, SIZE);

    //array of vertices;
    struct Vertex *v1 = makeVertex("San Francisco");
    struct Vertex *v2 = makeVertex("New York");
    struct Vertex *v3 = makeVertex("Chicago");
    struct Vertex *v4 = makeVertex("Dallas");
    struct Vertex *v5 = makeVertex("Las Vegas");

    struct Vertex *vertexList[] = {v1, v2, v3, v4, v5};

    //stack for dfs()
    struct Stack *stack = makeStack(SIZE);


    //make edges
    connectVertices(*graph, 0, 1);
    connectVertices(*graph, 0, 3);
    connectVertices(*graph, 1, 2);
    connectVertices(*graph, 4, 3);

    printGraph(*graph, SIZE);


    dfs(*graph, stack);



}