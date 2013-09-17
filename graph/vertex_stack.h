#ifndef MATTS_VSTACK
#define MATTS_VSTACK

//turned out I didnt need a stack of vertex struct pointers
//leaving it here cause I learned a thing or two
struct vStack {
    int size;
    int position;
    struct Vertex *vertices[];
};

struct Stack *makeVStack(int size);
void vpush(struct vStack *stack, struct Vertex *vertex);
struct Vertex *vpop(struct vStack *stack);
struct Vertex *vpeek(struct vStack *stack);
int isVEmpty(struct vStack *stack);

#endif