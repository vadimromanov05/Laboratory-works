#include <stdio.h>
#include <stdlib.h>

#define STR_SIZE 80

typedef struct {
    char name[STR_SIZE];
    char surname[STR_SIZE];

    int salary;
} Employee;

void employee_write(Employee *e, FILE *f)
{
    fwrite(&e->name, sizeof(e->name[0]), STR_SIZE, f);
    fwrite(&e->surname, sizeof(e->name[0]), STR_SIZE, f);
    fwrite(&e->salary, sizeof(e->salary), 1, f);
}

void employee_read(Employee *e, FILE *f)
{
    fread(&e->name, sizeof(e->name[0]), STR_SIZE, f);
    fread(&e->surname, sizeof(e->name[0]), STR_SIZE, f);
    fread(&e->salary, sizeof(e->salary), 1, f);
}

void employee_print(Employee *e)
{
    printf("Name: %.80s\n", e->name);
    printf("Surname: %.80s\n", e->surname);
    printf("Salary: %u\n", (unsigned int) e->salary);
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        printf("Usage: '%s w' to write, '%s r' to read\n", argv[0], argv[0]);
        exit(0);
    }

    Employee employees[] = {
        { "Vasiliy", "Petrov", 80000 },
        { "Maksim", "Trankov", 50000 },
        { "Evgeniy", "Dedutchev", 60000 },
        { "Vagit", "Rybman", 120000 }
    };
    int employees_qty = sizeof(employees) / sizeof(Employee);

    FILE *f = NULL;

    if (argv[1][0] == 'w') {
        f = fopen("employees.bin", "w");

        fwrite(&employees_qty, sizeof(employees_qty), 1, f);
        for (int i = 0; i < employees_qty; ++i) {
            employee_write(employees + i, f);
        }
    } else if (argv[1][0] == 'r') {
        f = fopen("employees.bin", "r");

        Employee employee_fetched;
        fread(&employees_qty, sizeof(employees_qty), 1, f);
        for (int i = 0; i < employees_qty; ++i) {
            employee_read(&employee_fetched, f);

            employee_print(&employee_fetched);
            printf("\n");
        }
    } else {
        printf("Usage: '%s w' to write, '%s r' to read\n", argv[0], argv[0]);
        exit(2);
    }

    return 0;
}
