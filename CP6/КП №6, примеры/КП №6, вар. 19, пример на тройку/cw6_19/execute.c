#include <stdio.h>
#include <stdlib.h>

#include "student.h"
#include "io.h"

typedef struct {
    double avg_mark;
    int group;
} StudentStatistics;

double avg_mark(Student *s)
{
    return (s->dm + s->ma + s->la + s->cs + s->hi) / 5.0;
}

// Using qsort is better, but requires proficiency with pointers :)
void sort(int arr[], int length)
{
    int tmp;
    for (int i = 1; i < length; ++i) {
        for (int j = i; j > 0 && arr[j - 1] > arr[j]; --j) {
            tmp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = tmp;
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage:\n\t./execute DB_FILE\n");
        exit(0);
    }

    FILE *in = fopen(argv[1], "r");
    if (!in) {
        printf("I/O Error: can't open file.\n");
        exit(1);
    }

    double avg = 0.0, min_avg = 1000000.0;

    // Each Student maps to { his average mark, his group }
    StudentStatistics students[200] = { { 0.0, -1 } };
    int students_qty = 0;

    // If student's average mark is minimal, his group number appends to min_avg_groups[]
    int min_avg_groups[200] = { -1 };
    int min_avg_groups_qty = 0;

    Student student;

    // Gathering statistics for each student and finding globally minimal average mark
    while (student_read_bin(&student, in)) {
        avg = avg_mark(&student);
        if (avg <= min_avg) {
            min_avg = avg;
        }
        students[students_qty++] = (StudentStatistics) {
            avg, student.group
        };
    }

    fclose(in);

    // For each student with minimal average add his group's number to min_avg_groups
    for (int i = 0; i < students_qty; ++i) {
        if (students[i].avg_mark == min_avg) {
            min_avg_groups[min_avg_groups_qty++] = students[i].group;
        }
    }

    // Sorting makes counting easy (equal group numbers will be neighbours in sorted array)
    sort(min_avg_groups, min_avg_groups_qty);

    // gap == size of equal numbers' block, max_idx -- index of largest group's first appearance
    int max_gap = -1;
    int max_idx = -1;
    int gap = 0;
    int prev = min_avg_groups[0];

    for (int i = 1; i < min_avg_groups_qty; ++i) {
        if (min_avg_groups[i] == prev) {
            ++gap;
        } else if (gap > max_gap) {
            max_gap = gap;
            max_idx = i - 1;
        }
    }
    // Last check to catch if last iteration produced gap, bigger than max_gap
    if (gap > max_gap) {
        max_gap = gap;
        max_idx = min_avg_groups_qty - 1;
    }

    if (max_idx >= 0)
        printf("%d\n", min_avg_groups[max_idx]);

    return 0;
}
