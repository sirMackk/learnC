#include <stdio.h>


int main(int argc, char *argv[]) {
    int i = 0;

    char *states[] = {"Oregon", "New York", "Texas", "California"};
    int num_states = sizeof(states)/sizeof(states[0]);
    for(i = 0; i < num_states; i++) {
        printf("State: %s\n", states[i]);
    }

    char *vars[sizeof(argv[0]) * argc];

    for(i = 0; i < argc; i++) {
        vars[i] = argv[i];

    }

    for(i = 1; i < argc; i++) {
        printf("arg %d: %s\n", i, vars[i]);
        
    }

    return 0;
}