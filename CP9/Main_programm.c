#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "table.h"

void binaryInsert(Table table[], int n) {
    for (int i = 0; i < n; i++) {
        table[i].key = 0.0; 
        memset(table[i].data, 0, sizeof(table[i].data));
        printf("\nТаблица до сортировки:\n");
        for (int j = 0; j < i; j++) {
            printf("Элемент %d: Ключ=%.2f, Данные=%s\n", j + 1, table[j].key, table[j].data);
        }
        printf("\nЭлемент %d:\n", i + 1);
        printf("Ключ: ");
        scanf("%f", &table[i].key);
        printf("Данные: ");
        getchar(); 
        fgets(table[i].data, 50, stdin);


        Table temp = table[i]; 
        int left = 0;
        int right = abs(i - 1);
        while (left <= right) {
            int mid = (left + right) / 2;
            if (temp.key < table[mid].key) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        for (int j = i - 1; j >= left; j--) {
            table[j + 1] = table[j];
        }
        table[left] = temp;
    }
}

int binarySearch(const Table table[], int n, float searchKey) {
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (table[mid].key == searchKey) {
            return mid;
        } else if (table[mid].key < searchKey) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; 
}

int main() {
    Table table[MAX_SIZE];
    int n;

    
    printf("Введите количество элементов в таблице (не более %d): ", MAX_SIZE);
    scanf("%d", &n);

    if (n > MAX_SIZE) {
        printf("Превышено максимальное количество элементов.\n");
        return 1;
    }
    binaryInsert(table, n);

    
    printf("\nОтсортированная таблица:\n");
    for (int i = 0; i < n; i++) {
        printf("Элемент %d: Ключ=%.2f, Данные=%s", i + 1, table[i].key, table[i].data);
    }

    float searchKey;
    printf("\nВведите ключ для поиска: ");
    scanf("%f", &searchKey);

    int result = binarySearch(table, n, searchKey);
    if (result != -1) {
        printf("Элемент с ключом %.2f найден. Данные: %s\n", table[result].key, table[result].data);
    } else {
        printf("Элемент с ключом %.2f не найден.\n", searchKey);
    }
    return 0;
}