#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    float data;
    struct Node* firstChild;
    struct Node* nextSibling;
} Node;

Node* createNode(float data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Ошибка выделения памяти\n");
        exit(1);
    }
    newNode->data = data;
    newNode->firstChild = NULL;
    newNode->nextSibling = NULL;
    return newNode;
}

void addChild(Node* parent, float data) {
    if (!parent) return;
    Node* child = createNode(data);
    if (!parent->firstChild) {
        parent->firstChild = child;
    } else {
        Node* temp = parent->firstChild;
        while (temp->nextSibling) {
            temp = temp->nextSibling;
        }
        temp->nextSibling = child;
    }
}

void printTree(Node* root, int level) {
    if (!root) return;
    for (int i = 0; i < level; i++) printf(" ");
    printf("%.2f\n", root->data);
    if (root->firstChild) {
        printTree(root->firstChild, level + 1);
    }
    if (root->nextSibling) {
        printTree(root->nextSibling, level);
    }
}

Node* findNode(Node* root, float data) {
    if (!root) return NULL;
    if (root->data == data) return root;
    Node* found = findNode(root->firstChild, data);
    if (found) return found;
    return findNode(root->nextSibling, data);
}

void addNode(Node** root) {
    float parentData, childData;
    printf("Введите родительский узел и значение нового узла (например, 1.5 2.3): ");
    if (scanf("%f %f", &parentData, &childData) != 2) {
        printf("Некорректный ввод.\n");
        exit(1);
    }
    if (parentData == 0) {
        if (*root == NULL) {
            *root = createNode(childData);
        } else {
            printf("Корень уже существует.\n");
        }
    } else {
        Node* parent = findNode(*root, parentData);
        if (parent) {
            addChild(parent, childData);
        } else {
            printf("Родительский узел не найден.\n");
        }
    }
}

int get_variant() {
    int variant;
    char s[5];
    scanf("%s", s);

    while (sscanf(s, "%d", &variant) != 1 || variant < 1 || variant > 5) {
        printf("Incorrect input. Try again: "); 
        scanf("%s", s);
    }

    return variant;
}

void deleteChild(Node *parent, Node *child) {
    Node *current = parent->firstChild;
    Node *prev = NULL;

    while (current != child && current != NULL) {
        prev = current;
        current = current->nextSibling;
    }

    if (current == child) {
        if (prev == NULL) {
            parent->firstChild = current->nextSibling;
        } else {
            prev->nextSibling = current->nextSibling;
        }
        free(current);
    }
}

int main() {
    Node* root = NULL;
    int variant;
    while (variant != 5){
        printf("What do you want to do?\n");
        printf("1: Add a root\n");
        printf("2: Print a tree\n");
        printf("3: Find a tree's width\n");
        printf("4: Delete node\n");
        printf("5: Exit\n");
        printf(">");
        variant = get_variant();
        switch(variant) {
            case 1:
                addNode(&root);
                break;
            case 2:
                printTree(root, 0);
                break;
            case 3:
                break;
            case 4:
                
                deleteChild(parent, child);
                break;
            case 5:
                system("pause");
        }
    }
}