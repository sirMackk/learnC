#include <stdlib.h>
#include "queue.h"

struct Queue *makeQueue(int size)
{
    //check if this size includes space for struct
    struct Queue *q = calloc(sizeof(int), size);

    q->start = 0;
    q->end = 0;
    q->size = size;

    return q;
}

int isQEmpty(struct Queue *q)
{
    if(q->start == q->end)
        return 1;
    else
        return 0;
}

void qpush(struct Queue *q, int value)
{
    q->queue[q->end++] = value;
}

int qpop(struct Queue *q)
{
    return q->queue[q->start++];
}