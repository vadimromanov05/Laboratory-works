#ifndef table_h
#define table_h
#define MAX_SIZE 20

typedef struct {
    float key;
    char data[50];
} Table;

void binaryInsert(Table table[], int n);
int binarySearch(const Table table[], int n, float searchKey);

#endif