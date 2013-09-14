#ifndef MATTS_BINARY_TREE
#define MATTS_BINARY_TREE

struct Node {
    int value;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int value);
struct Node *insertNode(struct Node *root, struct Node *node);
struct Node *deleteNode(struct Node *root, int value, struct Node *prev);
struct Node *searchNode(struct Node *node, int value);
int printNode(struct Node *node);
void printNodes(struct Node *root);
struct Node *findSuccessor(struct Node *node);
struct Node *findSuccessorParent(struct Node *node);

#endif