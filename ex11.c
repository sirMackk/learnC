#include <stdio.h>

int main(int argc, char *argv[]) {

    int i = 0;
    while(i < argc) {
        printf("arg %d: %s\n", i, argv[i]);
        i++;
    }

    char *states[] = {"California", "Oregon", "Texas", "New York"};

    int k = sizeof(states) / sizeof(states[0]);
    i = 0;
    while(i < k) {
        printf("states %d: %s\n", i, states[i]);
        i++;
    }

    return 0;
}