#ifndef LIST_H
#define LIST_H

#include <stdbool.h>
#include <stdlib.h>


typedef struct Node {
    size_t data;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
} List;

typedef struct Iterator {
    Node* node;
} Iterator;

List *list_create();
Node* find_node(Iterator* it, List* list, size_t value);
Node* find_to_delete(Iterator* it, List* list, size_t value);
void delete_value(Iterator* it, List* list, size_t value);
void mega_delete(Iterator* it, List* list, size_t value);
void list_insert(Iterator* it, List* list, size_t prev_data, size_t value);
void list_destroy(List *list);
int len(Iterator* it, List* l);


Iterator *iter_create(List *list);
Node *iter_next(Iterator *iter);
void iter_set(Iterator *iter, size_t value);
size_t iter_get(Iterator *iter);
Iterator* find_iter(Iterator* it, List* list, size_t value);



#endif