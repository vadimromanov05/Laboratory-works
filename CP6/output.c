#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "person.h"

int main() {
    Person p;
    FILE *out = fopen("test_file.bin", "rb");
    fread(&p.name, sizeof(p.name), 1, out);
    fclose(out);
    return 0;
}