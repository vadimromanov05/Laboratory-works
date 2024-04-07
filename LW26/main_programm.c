#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#include "dack.h"

void initDeque(struct Deque* deque) {
    deque->front = NULL;
    deque->rear = NULL;
}

void addFront(struct Deque* deque, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = deque->front;
    newNode->prev = NULL;
    if (deque->front) {
        deque->front->prev = newNode;
    }
    deque->front = newNode;
    if (deque->rear == NULL) {
        deque->rear = newNode;
    }
}

void addRear(struct Deque* deque, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = deque->rear;
    if (deque->rear) {
        deque->rear->next = newNode;
    }
    deque->rear = newNode;
    if (deque->front == NULL) {
        deque->front = newNode;
    }
}

int removeFront(struct Deque* deque) {
    if ((deque->front == NULL) && (deque->rear == NULL)) {
        return -1; // Дек пуст
    }
    struct Node* temp = deque->front;
    int data = temp->data;
    deque->front = deque->front->next;
    if (deque->front == NULL) {
        deque->rear = NULL;
    } else {
        deque->front->prev = NULL;
    }
    free(temp);
    return data;
}

int removeRear(struct Deque* deque) {
    if ((deque->front == NULL) && (deque->rear == NULL)) {
        return -1; // Дек пуст
    }
    struct Node* temp = deque->rear;
    int data = temp->data;
    deque->rear = deque->rear->prev;
    if (deque->rear == NULL) {
        deque->front = NULL;
    } else {
        deque->rear->next = NULL;
    }
    free(temp);
    return data;
}

void clearDeque(struct Deque* deque) {
    while (deque->front) {
        struct Node* temp = deque->front;
        deque->front = deque->front->next;
        free(temp);
    }
    deque->rear = NULL;
}

void printMenu() {
    printf("\nВыберите операцию:\n");
    printf("1. Добавить элемент в начало дека\n");
    printf("2. Добавить элемент в конец дека\n");
    printf("3. Удалить элемент с начала дека\n");
    printf("4. Удалить элемент с конца дека\n");
    printf("5. Сортировка дека\n");
    printf("6. Выход\n");
    printf(">");
}

int len(struct Deque* deque, struct Deque* help_deque) {
    if ((deque->front == NULL) && (deque->rear == NULL)) {
        return -1;
    }
    int buf;
    int deque_len = 0;
    while (deque->rear || deque->front) {
        buf = removeRear(deque);
        addFront(help_deque, buf);
        deque_len++;
    }
    clearDeque(deque);
    while (help_deque->front || help_deque->rear) {
        buf = removeRear(help_deque);
        addFront(deque, buf);
    }
    clearDeque(help_deque);
    return deque_len;
}

int maxElement(struct Deque* deque, struct Deque* help_deque) {
    int buf = 0, max_element = INT_MIN, pos = 0, c_pos, i;
    int d_len = len(deque, help_deque), len2 = d_len;
    if (d_len == -1) {
        return -1;
    }
    while (len2 > 0){
        max_element = INT_MIN;
        for (i = 0; i < len2; i++) {
            buf = removeRear(deque);
            if (buf >= max_element) {
                max_element = buf;
                pos = i;
            }
            addFront(help_deque, buf);
        }
        for (i = 0; i < pos; i++){
            buf = removeRear(help_deque);
            addRear(deque, buf);
        }
        buf = removeRear(help_deque);
        addFront(deque, buf);
        for (i = pos + 1; i < len2; i++) {
            buf = removeFront(help_deque);
            addRear(deque, buf);
        }
        clearDeque(help_deque);
        len2--;
    }
    for (int i = 0; i < d_len; i++) {
        buf = removeFront(deque);
        printf("%d ", buf);
        addRear(deque, buf);
    }
    
}

int main() {
    struct Deque deque;
    initDeque(&deque);
    struct Deque help_deque;
    initDeque(&help_deque);
    int choice, data;

    do {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                printf("ERROR! Rebuild the programm, dumkopf!");
                break;
            case 1:
                printf("Введите значение: ");
                scanf("%d", &data);
                addFront(&deque, data);
                break;
            case 2:
                printf("Введите значение: ");
                scanf("%d", &data);
                addRear(&deque, data);
                break;
            case 3:
                data = removeFront(&deque);
                if (data == -1) {
                    printf("Дек пуст\n");
                } else {
                    printf("Удаленный элемент: %d\n", data);
                }
                break;
            case 4:
                data = removeRear(&deque);
                if (data == -1) {
                    printf("Дек пуст\n");
                } else {
                    printf("Удаленный элемент: %d\n", data);
                }
                break;
            case 5:
                data = maxElement(&deque, &help_deque);
                break;
            case 6:
                clearDeque(&deque);
                printf("Дек очищен\n");
                break;
            default:
                printf("Неверный выбор\n");
        }
    } while (choice != 6);

    return 0;
}