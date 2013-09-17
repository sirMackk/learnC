#ifndef MATTS_QUEUE
#define MATTS_QUEUE

//primative queue

struct Queue {
    int start;
    int end;
    int size;
    int queue[];
};

struct Queue *makeQueue(int size);
int isQEmpty(struct Queue *q);
int qpop(struct Queue *q);
void qpush(struct Queue *q, int value);


#endif



