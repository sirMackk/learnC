#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Reading {
    char date[10];
    float day;
    float night;
};

int main(int argc, char *argv[])
{
    int i;

    if(argc < 3) {
        fprintf(stderr, "\n\nUsage: ./mwrite dd/mm/yyyy day night\n\n\n");
        exit(1);
    }

    FILE *fp;
    if((fp = fopen("mreadings.dat", "rb+")) == NULL) {
        fprintf(stderr, "\nError: Couldnt open mreadings.dat!\n\
            Creating empty file!\n");
        fp = fopen("mreadings.dat", "wb+");
        struct Reading empties[30];
        for(i = 0; i < 30; i++) {
            strcpy(empties[i].date, "NULL");
            empties[i].day = 0.0f;
            empties[i].night = 0.0f;
        }
        fwrite(empties, sizeof(struct Reading), 30, fp);
        fclose(fp);
        exit(1);
    }

    struct Reading readings[30];
    fread(readings, sizeof(struct Reading), 30, fp);
    rewind(fp);
    for(i = 0; readings[i].day != 0; i++) {
    }

    float tmp;
    strcpy(readings[i].date, argv[1]);
    //use sscanf to convert string into float by
    //sscanf(string, seive, output location)
    sscanf(argv[2], "%f", &tmp);
    readings[i].day = tmp;
    sscanf(argv[3], "%f", &tmp);
    readings[i].night = tmp;

    fwrite(readings, sizeof(struct Reading), 30, fp);

    printf("Done writing!\n");
    fclose(fp);
    return 0;



}