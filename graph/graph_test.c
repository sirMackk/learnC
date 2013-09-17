#include "graph.h"
#include "stack.h"
#include "queue.h"


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

    //make edges
    connectVertices(*graph, 0, 1);
    connectVertices(*graph, 0, 3);
    connectVertices(*graph, 1, 2);
    connectVertices(*graph, 4, 3);

    printGraph(*graph, SIZE);

    //gotta pass in dat vertexlist yo
    dfs(*graph, vertexList);

    bfs(*graph, vertexList);



}