#include <stdio.h>

int main(int argc, char *argv[]) {
    int bugs = 100;
    double bug_rate = 1.2;

    printf("expected bugs: %f\n", bugs * bug_rate);

    long defects = 1L * 1024L * 1024L * 1024L;
    printf("Number of defects: %ld\n", defects);

    double part_defects = bugs * bug_rate / defects;
    printf("Portions: %e\n", part_defects);

    char null_byte = '\0';
    int c_percentage = bugs * null_byte;
    printf("Fucks given: %d%%.\n", c_percentage);

    return 0;
}