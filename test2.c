#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//simple file writing + struct example

struct Bebs {
    int id;
    char c[32];
};

int main(int argc, char *argv[])
{
    FILE *file;
    char c[] = "bebs bybs";
    char buffer[20];

    file = fopen("test.txt", "w+");
    fwrite(c, strlen(c) + 1, 1, file);
    fclose(file);

    file = fopen("test.txt", "r");
    fread(buffer, strlen(c) + 1, 1, file);
    printf("%s\n", buffer);
    fclose(file);

    struct Bebs *bb = malloc(sizeof(struct Bebs));
    bb->id = 4;
    strcpy(bb->c, "struct test");
    file = fopen("test2.txt", "w+");
    fwrite(bb, sizeof(struct Bebs), 1, file);

    fseek(file, SEEK_SET, 0);

    struct Bebs *cc = malloc(sizeof(struct Bebs));
    fread(cc, sizeof(struct Bebs), 1, file);
    fclose(file);
    printf("%s\n", cc->c);

    return(0);
}