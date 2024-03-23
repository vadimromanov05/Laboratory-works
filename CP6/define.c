#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "person.h"

void usage() {
    printf("Usage: programm filename\n");
}

int readperson(Person *p) {
    return scanf("%s\t%d\n", &p->name, &p->school_number) == 2;
}

int main() {
    Person p;
    scanf("%s %s", &p.name, &p.initials);
    p.school_number = 123;
    FILE *in = fopen("test_file.bin", "wb");
    fwrite(&p.name, sizeof(p.name), 1, in);
    fclose(in);
    printf("%s %s\n%d", p.name, p.initials, p.school_number);
}