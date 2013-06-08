#include <stdio.h>

int main(int argc, char *argv[]) {
    int distance = 100;
    float power = 2.345f;
    double super_power = 12313.123123;
    char initial = 'A';
    char first_name[] = "Matt";

    printf("This is: %d.\n", distance);
    printf("Power: %f.\n", power);
    printf("Super power: %f.\n", super_power);
    printf("This is an initial: %c.\n", initial);
    printf("This is a char array: %s. And the distance again: %d.\n",
            first_name, distance);

    return 0;
}