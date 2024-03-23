#include <stdio.h>
#include <stdlib.h>

#define STR_SIZE 80

typedef struct {
    char name[STR_SIZE];
    char surname[STR_SIZE];

    int salary;
} Employee;

Employee e = {
    "Vasiliy",
    "Petrov",
    80000
};

Employee e2;

void employee_write(char *storage_path)
{
    FILE *out = fopen(storage_path, "wb");

    if (!out) {
        fprintf(stderr, "I/O Error: can't open file.\n");
        exit(1);
    }

    fwrite(e.name, sizeof(e.name[0]), STR_SIZE, out);
    fwrite(e.surname, sizeof(e.name[0]), STR_SIZE, out);
    fwrite(&e.salary, sizeof(e.salary), 1, out);

    fclose(out);
}

void employee_read(char *storage_path)
{
    FILE *in = fopen(storage_path, "rb");

    if (!in) {
        printf("I/O Error: can't open file.\n");
        exit(1);
    }

    fread(e2.name, sizeof(e2.name[0]), STR_SIZE, in);
    fread(e2.surname, sizeof(e2.name[0]), STR_SIZE, in);
    fread(&e2.salary, sizeof(e2.salary), 1, in);

    fclose(in);
}

void employee_print(Employee e)
{
    printf("Name: %.80s\n", e.name);
    printf("Surname: %.80s\n", e.surname);
    printf("Salary: %u\n", (unsigned int) e.salary);
}

int main(int argc, char **argv)
{
    employee_write("struct.bin");
    employee_read("struct.bin");

    employee_print(e2);

    return 0;
}
