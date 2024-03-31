#ifndef deque_h
#define deque_h

#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Deque {
    struct Node* front;
    struct Node* rear;
};

void initDeque(struct Deque* deque);
void addFront(struct Deque* deque, int data);
void addRear(struct Deque* deque, int data);
int removeFront(struct Deque* deque);
int removeRear(struct Deque* deque);
void clearDeque(struct Deque* deque);
void printMenu();
int len(struct Deque* deque, struct Deque* help_deque);
int maxElement(struct Deque* deque, struct Deque* help_deque);
#endif