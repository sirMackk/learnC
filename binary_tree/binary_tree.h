#ifndef MATTS_BINARY_TREE
#define MATTS_BINARY_TREE

struct Node {
    int value;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int value);
struct Node *insertNode(struct Node *root, struct Node *node);
struct Node *deleteNode(struct Node *node);
struct Node *searchNode(int value);
void printNode(struct Node *node);
void printNodes(struct Node *root);

#endif