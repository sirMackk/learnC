#include <stdio.h>

int main(int argc, char *argv[]) {

    int areas[] = {10, 12, 13, 14, 20};
    char name[] = "Matt";
    char full_name[] = {'M', 'A', 'T', 'T'};


    printf("The size of an int: %u\n", sizeof(int));
    printf("The size of areas[]: %u\n", sizeof(areas));
    printf("The number of ints in areas: %u\n", sizeof(areas) / sizeof(int));
    printf("The size of a char: %u\n", sizeof(char));
    printf("The size of name[]: %u\n", sizeof(name));
    printf("The number of chars: %u\n", sizeof(name) / sizeof(char));
    printf("The size of full_name: %u\n", sizeof(full_name));
    printf("The number of chars in full_name: %u\n", sizeof(full_name) / sizeof(char));
    printf("Name=\"%s\" and full_name=\"%s\"\n", name, full_name);

    areas[0] = 55;
    printf("\n\n%d\n\n", areas[0]);

    return 0;   
}