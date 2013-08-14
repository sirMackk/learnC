#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//slightly more complicated file writing example along with structs, pointers and args
// needs moar pointers

struct Note {
    int id;
    char note[256];
};

void Write_note(char *name, char *data)
{
    struct Note *note = malloc(sizeof(struct Note));
    FILE *file = fopen(name, "w");
    note->id = 1;
    strcpy(note->note, data);
    int rc = fwrite(note, sizeof(struct Note), 1, file);
    if(rc != 1) printf("Can't write to file");
    fflush(file);
    fclose(file);
}

void Display_note(struct Note *note)
{
    printf("displaying note\n");
    printf("Note id: %d\n", note->id);
    printf("Note: %s\n", note->note);
}

void Read_file(char *name)
{

    struct Note *note = malloc(sizeof(struct Note));
    
    FILE *file = fopen(name, "r");
    int rc = fread(note, sizeof(struct Note), 1, file);
    fclose(file);
    if(rc != 1) {
        printf("There was an error in reading the file\n");
        exit(1);
    } else if(rc == 1) {
        Display_note(note);
    }
}

int main(int argc, char *argv[])
{
    char *filename = argv[1];
    char action = argv[2][0];

    switch(action) {
        case 'w':
        printf("writing...\n");
            Write_note(filename, argv[3]);
            break;
        case 'r':
            printf("reading file\n");
            Read_file(filename);
            break;

        default:
            printf("Wrong parameters\n");
    }

    return 0;

}