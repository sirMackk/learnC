#ifndef MATTS_LINKED_LIST
#define MATTS_LINKED_LIST

#define INT_SIZE sizeof(int)
#define FLOAT_SIZE sizeof(float)
#define CHAR_SIZE sizeof(char)
#define NODE_TYPE_SIZE sizeof(enum node_type)
#define NODE_POINTER_SIZE sizeof(struct Node *)

enum node_type {
    intNode, floatNode, stringNode
};

struct Node {
    enum node_type type;
    struct Node *next;
    union {
        int i;
        float f;
    } u;
    char c[];

};

struct Node *createNode(int size, enum node_type type);
struct Node *createNodeString(int size, char item[]);
int destroyNode(struct Node *first, struct Node *node);
void printNodes(struct Node *node);
void printNode(struct Node *node);
struct Node *searchIntNode(struct Node *node, int n);
struct Node *searchFloatNode(struct Node *node, float n);
struct Node *searchStringNode(struct Node *node, char *n);
struct Node *insertNode(struct Node *first, struct Node *node);

#endif