#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_ENTRIES 30

struct Entry {
    char date[11];
    float day;
    float night;
};

int main(void)
{
    FILE *fp;

    int i;
    if((fp = fopen("readings.dat", "rb+")) == NULL) {
        fprintf(stderr, "Cannot open readings.dat\n\
            Creating file from scratch..\n");
        fp = fopen("readings.dat", "wb+");
        struct Entry empty[MAX_ENTRIES];
        for(i = 0; i < MAX_ENTRIES; i++) {
            strcpy(empty[i].date, "NULL");
            empty[i].day = 0.0f;
            empty[i].night = 0.0f;

        }
        fwrite(empty, sizeof(struct Entry), MAX_ENTRIES, fp);
        fclose(fp);
        printf("%lu\n", sizeof(struct Entry) * MAX_ENTRIES);
        printf("open again...\n");
        return(1);
    }

    printf("Press r to read whole list or w to make an entry\n");
    char choice = getchar();

    char tmp_date[11];
    float tmp_day;
    float tmp_night;
    struct Entry entries[MAX_ENTRIES];
    fread(entries, sizeof(struct Entry), MAX_ENTRIES, fp);


    switch(choice) {
        case 'r':
            for(i = 0; i < MAX_ENTRIES; i++) {
                if(entries[i].day == 0) break;
                printf("%d--Date: %s\n", i, entries[i].date);
                printf("Day: %0.1f\n", entries[i].day);
                printf("Night: %0.1f\n", entries[i].night);

            }
            printf("Total day difference: %0.1fkW/h\n", (entries[i - 1].day - entries[0].day));
            printf("Approximate day cost to date: %0.2feur\n", ((entries[i - 1].day - entries[0].day) * 0.20f));
            printf("Total night difference: %0.1fkW/h\n", entries[i - 1].night- entries[0].night);
            printf("Approximate night cost to date: %0.2feur\n", ((entries[i - 1].night - entries[0].night) * 0.09f));

            printf("Total cost: %0.2f euros\n", ((entries[i - 1].day - entries[0].day) * 0.20f) + ((entries[i - 1].night - entries[0].night) * 0.09f));
            break;
        case 'w':
            for(i = 0; i < MAX_ENTRIES; i++) {
                if(entries[i].day == 0) break;
            }
            printf("Input today's date (dd/mm/yyyy):\n");
            scanf("%s", tmp_date);
            printf("Input today's day reading:\n");
            scanf("%f", &tmp_day);
            printf("Input today's night reading:\n");
            scanf("%f", &tmp_night);

            strncpy(entries[i].date, tmp_date, 11);
            entries[i].day = tmp_day;
            entries[i].night = tmp_night;

            break;
        default:
            printf("Wrong choice, exiting...\n");
            break;

    }
    rewind(fp);
    fwrite(entries, sizeof(struct Entry), MAX_ENTRIES, fp);
    fclose(fp);

    return 0;

}