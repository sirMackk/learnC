#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define START1 0
#define START2 1
#define MAX_NAME 32

int getInt(int b);
void power(int *b);
int *max(int *a, int *b);
int *find_last(int k[]);



int main(int argc, char *argv[])
{
    printf("Starting...\n");
    printf("Power: %d\n", getInt(2));

    int i;
    i = 8;
    printf("size of i: %d\n", (int)sizeof(i));
    int *p = &i;
    printf("points to i: %d\n", *p);
    printf("address: %p\n", &i);
    *p = 16;
    printf("points to i: %d\n", *p);
    printf("address: %p\n", &i);

    power(&i);
    printf("points to i: %d\n", *p);



    // char *name[] = "Bebs";

    int j;
    scanf("%d", &j);
    printf("number: %d\n", j);

    int *k;

    k = max(&i, &j);
    printf("max: %d\n", *k);

    int w[] = {1, 2, 3, 4};
    printf("first: %d\n", *find_last(w));
    *find_last(w) = 5;
    printf("first: %d\n", *find_last(w));



    return 0;
}

int getInt(int b)
{
    return b * b;
}

void power(int *b)
{
    *b *= *b;
}

int *max(int *a, int *b)
{
    if(*a > *b)
        return a;
    else
        return b;
}

int *find_last(int k[])
{
    return &k[0];
}