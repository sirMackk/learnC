#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Reading {
    char date[10];
    float day;
    float night;
};

int main(void)
{
    FILE *fp;
    if((fp = fopen("mreadings.dat", "rb+")) == NULL) {
        fprintf(stderr, "Error reading mreadings file!\n");
        exit(1);
    }

    struct Reading readings[30];
    fread(readings, sizeof(struct Reading), 30, fp);
    fclose(fp);
    int i;
    for(i = 0; readings[i].day != 0; i++) {
        printf("Date: %s, Day: %f, Night: %f\n", readings[i].date,
            readings[i].day, readings[i].night);
    }

    return 0;
}