#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

struct Test {
    int code;
    char *name;
};

struct Test *Create_test(int code, char *name)
{
    struct Test *test = malloc(sizeof(struct Test));
    assert(test != NULL);

    test->code = code;
    test->name = strdup(name);

    return test;
}

void Print_test(struct Test *test)
{
    printf("Test code: %d\n", test->code);
    printf("Test name: %s\n", test->name);
}

void Destroy_test(struct Test *test)
{
    assert(test != NULL);
    free(test->name);
    free(test);
}

int main(int argc, char *argv[])
{
	int number = 11;
	int numbers[] = {1, 2, 3};

	char letter = 'a';
	char *word = "bebs";
	char *words[] = {"bybs", "bebs"};

	printf("%d is a number\n", number);	
	printf("Going to print an array of numbers:\n");
    int length = sizeof(numbers) / sizeof(int);
    int i = 0;
    for(i = 0; i < length; i++) {
        printf("Number: %d\n", numbers[i]);
    }

    printf("printing character %c\n", letter);
    printf("printing a whole word: %s\n", word);
    length = sizeof(words);
    printf("length of whole words variable %d\n", length);
    printf("size of char: %lu\n", sizeof(*words));
    length = sizeof(words) / sizeof(*words);
    for(i = 0; i < length; i++) {
        printf("word: %s\n", words[i]);
    }

    printf("Now I'm gonna make a struct:\n");

    struct Test *dude = Create_test(12, "Joe");
    printf("Dude is at the location: %p\n", dude);
    printf("AND operator before var?: %p\n", &dude);
    Print_test(dude);
    Destroy_test(dude);


    return 0;
}

