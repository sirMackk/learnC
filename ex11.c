#include <stdio.h>

int main(int argc, char *argv[]) 
{
    int i = 0;

    if(argc == 1) {
        printf("You only gave one argument");
    } else if(argc > 1 && argc < 4) {
        printf("Here are your arguments:\n");

        for(i = 1; i < argc; i++) {
            printf("%s ", argv[i]);
        }
        printf("\n");
    } else {
        printf("Yo have too many arguments, man");
    }

    return 0;
}