#ifndef MATTS_GRAPH
#define MATTS_GRAPH
#define SIZE 5

#define PRN(a) printf("%d\n", (a));

struct Vertex {
    int wasVisited;
    char data[25];
};

struct Vertex *makeVertex(char data[]);
void connectVertices(int graph[], int start, int end);
void directedConnect(int graph[], int start, int end);
void printGraph(int graph[], int size);

int getAdjacentVertex(int graph[], struct Vertex *vertexList[], int index);
void resetVisitedFlags(struct Vertex *vertexList[], int size);

void dfs(int graph[], struct Vertex *vertexList[]);
void bfs(int graph[], struct Vertex *vertexList[]);

#endif

