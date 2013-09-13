#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"

int main(void)
{

    char choice;
    int item;
    struct Node *first = createNode(INT_SIZE, intNode);
    first->type = intNode;
    struct Node *node;
    while(1) {
        puts("i - insert, d - delete, p - printall, x - exit");
        choice = getchar();

        switch(choice) {
            case 'i':
                puts("Enter integer to insert:");
                scanf("%d", &item);
                if(!first->u.i) {
                    first->u.i = item;
                } else {
                    node = createNode(INT_SIZE, intNode);
                    node->u.i = item; 
                    insertNode(first, node);
                }
                break;
            case 'd':
                if(!first) break;
                puts("Enter integer to delete:");
                scanf("%d", &item);
                destroyNode(first, searchIntNode(first, item));
                //check if node was actually deleted dude
                puts("Node deleted!");
                break;
            case 'p':
                if(!first) break;
                printNodes(first);
                break;
            case 'x':
                return 0;

        }

    }
    return 0;
}

