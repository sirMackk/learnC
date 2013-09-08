#include <stdio.h>

#define MAX 10
#define MIN "MIN"
//define macro FRAN that takes a and returns a^2
#define FRAN(a) ((a)*(a))

//define a macro that expands into a function
//with dynamic return type and parameters
#define GENERIC_MAX(type)       \
type type##_max(type x, type y) \
{                               \
    return x > y ? x : y;       \
}

#define DEBUG 0

//examples of above macro
GENERIC_MAX(float)
GENERIC_MAX(int)
void power(int *num);
int powpow(int num);

int main(int argc, char *argv[])
{
    int x = 2;
    int *p = &x;

    printf("X is %d\n", x);
    printf("X^2 is %d\n", powpow(x));
    power(p);
    printf("X^2 pointer is %d\n", x);

    int r[] = {7, 6, 5, 3};
    printf("p1 is %d\n", r[0]);
    printf("p2 is %d\n", *(r + 1));

    printf("%d\n", int_max(1, 3));


    #if DEBUG
    printf("Compiled on %s, %s by %d\n", __DATE__, __TIME__, __STDC__);
    printf("DEBUGGER MODE\n");
    #endif

    return 0;
}

void power(int *num)
{
    *num *= *num;
}

int powpow(int num)
{
    return num * num;
}