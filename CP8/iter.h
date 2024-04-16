#ifndef ITERATOR_H
#define ITERATOR_H

#include "list.h"

typedef struct Iterator {
    Node* node;
} Iterator;

Iterator *iter_create(List *list);
Node *iter_next(Iterator *iter);
void iter_set(Iterator *iter, size_t value);
size_t iter_get(Iterator *iter);
Iterator* find_iter(Iterator* it, List* list, size_t value);


#endif