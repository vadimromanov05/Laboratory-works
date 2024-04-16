#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "list.h"


Iterator *iter_create(List *list)
{
    Iterator *iter = (Iterator *) malloc(sizeof(Iterator));
    iter->node = list->head;
}

Node *iter_next(Iterator *iter)
{
    iter->node = iter->node->next;
    return iter->node;
}

void iter_set(Iterator *iter, size_t value)
{
    iter->node->data = value;
}

size_t iter_get(Iterator *iter)
{
    return iter->node->data;
}

Iterator* find_iter(Iterator* it, List* list, size_t value) {
    it->node = list->head;
    while (it->node->data != value) {
        it->node = it->node->next;
    }
    it->node = it->node->next;
    return it;
}

List *list_create()
{
    List *list = (List*) malloc(sizeof(List));
    
    list->head = (Node*) malloc(sizeof(Node));
    list->head->next = NULL;
    list->head->data = 0; /*Для удобства отладки*/

    return list;
}

Node* find_node(Iterator* it, List* list, size_t value) {
    Node *current = list->head;
    it->node = current;
    if (it->node->next == NULL) {
        return it->node;
    }
    while (it->node->next != NULL) {
        if (it->node->next->data != value) {
            it->node = it->node->next;
        }
        else {
            return it->node->next;
        }
    }
    if (it->node->next == NULL) {
        printf("Wrong element!\n\n");
        return NULL;
    }
    if (it->node->next->data == value) {
        return it->node->next;
    }
}

Node* find_to_delete(Iterator* it, List* list, size_t value) {
    Node *current = list->head;
    it->node = current;
    if (it->node->next == NULL) {
        printf("The list is empty!\n\n");
        return NULL;
    }
    while (it->node->next != NULL) {
        if (it->node->next->data != value) {
            it->node = current->next;
        }
        else {
            return it->node;
        }
    }
    if (it->node->next == NULL) {
        return NULL;
    }
    if (it->node->next->data == value) {
        return it->node;
    }
}

void delete_value(Iterator* it, List* list, size_t value) {
    Node* prev_node = find_to_delete(it, list, value);
    if (prev_node == NULL) {
        return;
    }
    Node* reserve = prev_node->next->next;
    it = find_iter(it, list, value);
    free(prev_node->next);
    prev_node->next = reserve;
}

void mega_delete(Iterator* it, List* list, size_t value) {
    int check = 0;
    it->node = list->head->next;
    while (it->node != NULL) {
        if (it->node->data == value) {
            check = 1;
        }
        iter_next(it);
    }
    if (check == 0) {
        printf("There is not this value in the list!\n\n");
        return;
    }

    it->node = list->head;
    if (it->node->next == NULL) {
        printf("The list is empty!\n\n");
        return;
    }
    it->node = it->node->next;
    while (it->node != NULL) {
        if (iter_get(it) != value) {
            delete_value(it, list, iter_get(it));
        }
        else {
            iter_next(it);
        }
    }
}

void list_insert(Iterator* it, List* list, size_t prev_data, size_t value)
{
    Node* prev_node = find_node(it, list, prev_data);
    if (prev_node == NULL) {
        return;
    }
    Node* inserted = (Node*) malloc(sizeof(Node));
    inserted->data = value;
    inserted->next = prev_node->next;
    prev_node->next = inserted;
}

void list_destroy(List *list)
{
    Node *n = list->head->next;
    while (list->head != NULL)
    {
        n = list->head->next;
        free(list->head);
        list->head = n;
    }
    list->head = NULL;
    free(list);
}

int len(Iterator* it, List* l) {
    int counter = 0;
    it->node = l->head->next;
    while (it->node != NULL) {
        counter++;
        iter_next(it);
    }
    return counter;
}

void print_list(Iterator* it, List* l) {
    it->node = l->head->next;
    while (it->node != NULL) {
        printf("%zu ", iter_get(it));
        iter_next(it);
    }
    printf("\n");
}

void print_menu() {
    printf("How do you want to crash this programm?\n");
    printf("1. Add a new element\n");
    printf("2. Print a list\n");
    printf("3. Delete an element\n");
    printf("4. Count a length of list\n");
    printf("5. Delete all elements before and after current value\n");
    printf("6. Exit\n");
    printf(">");
}

int main()
{
    size_t prev_value, value, head_value = 0;
    int variant = 0, counter = 0;
    List *l = list_create(100);
    Iterator *it = iter_create(l);
    while (variant != 6) {
        print_menu();
        scanf("%d", &variant);
        if (variant < 1 || variant > 6) {
            printf("Incorrect input! Try again!\n\n");
        }
        switch (variant)
        {
        case 1:
            printf("Insert a value which is already in a list (else insert 0): ");
            scanf("%zu", &prev_value);
            printf("Insert a new value: ");
            scanf("%zu", &value);
            list_insert(it, l, prev_value, value);
            printf("\n");
            break;
        case 2:
            print_list(it, l);
            printf("\n");
            break;
        case 3:
            printf("Insert a value which do you want to delete: ");
            scanf("%zu", &value);
            delete_value(it, l, value);
            break;
        case 4:
            printf("The lengh of list: %d\n", len(it, l));
            break;
        case 5:
            printf("Insert a value which do you want to save: ");
            scanf("%zu", &value);
            mega_delete(it, l, value);
            break;
        }
    }
    if (it != NULL) {
            free(it);
        }
        list_destroy(l);
        printf("List is clear! Programm is ended.\n");
    return 0;
}