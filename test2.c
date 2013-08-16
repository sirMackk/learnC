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
    //create pointer to file struct
    FILE *file;
    //create array of chars
    char c[] = "bebs bybs";
    //create empty array of 20 chars
    char buffer[20];

    //open test.txt with w+
    file = fopen("test.txt", "w+");
    //write char array c of length strlen + 1 as 1 chunk to file
    fwrite(c, strlen(c) + 1, 1, file);
    //close file
    fclose(file);

    //open file for reading
    file = fopen("test.txt", "r");
    //fill array of chars with strlen(c) number of characters
    //from file
    fread(buffer, strlen(c) + 1, 1, file);
    printf("%s\n", buffer);
    fclose(file);

    //create an empty Bebs struct in memory
    struct Bebs *bb = malloc(sizeof(struct Bebs));
    bb->id = 4;
    //copy string bytes into struct
    strcpy(bb->c, "struct test");
    file = fopen("test2.txt", "w+");
    //write bebs struct to file
    fwrite(bb, sizeof(struct Bebs), 1, file);
    //rewind file
    fseek(file, SEEK_SET, 0);
    //create another empty Bebs struct
    struct Bebs *cc = malloc(sizeof(struct Bebs));
    //read file data into newly created struct in memory
    fread(cc, sizeof(struct Bebs), 1, file);
    fclose(file);
    //print struct text
    printf("%s\n", cc->c);

    return(0);
}