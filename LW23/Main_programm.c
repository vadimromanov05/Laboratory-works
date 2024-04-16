#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    if (a >= b) {
        return a;
    }
    return b;
}

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

Node* findNode(Node* root, float data) {
    if (!root) return NULL;
    if (root->data == data) return root;
    Node* found = findNode(root->firstChild, data);
    if (found) return found;
    return findNode(root->nextSibling, data);
}

Node* findNode2(Node* root, float data) {
    if (!root) return NULL;
    if (root->data == data) {
        return root;
    }
    if (root->firstChild != NULL && root->nextSibling != NULL) {
        if ((root->firstChild->data == data) || (root->nextSibling->data == data)){
            return root;
        }
    }
    else if (root->firstChild != NULL) {
        if (root->firstChild->data == data){
            return root;
        }
    }
    else if (root->nextSibling != NULL) {
        if (root->nextSibling->data == data){
            return root;
        }
    }
    Node* found = findNode2(root->firstChild, data);
    if (found) return found;
    return findNode2(root->nextSibling, data);
}

void addNode(Node** root) {
    float parentData, childData;
    printf("Введите родительский узел и значение нового узла (для корня введите 0.0 число): ");
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

void printTree(Node* root, int level) {
    if (root == NULL) {
        return;
    }
    for (int i = 0; i < level; i++) {
        printf("  ");
    }
    printf("%f\n", root->data);
    printTree(root->firstChild, level + 1);
    printTree(root->nextSibling, level);
}

int getWidth(Node* root) {
    if (!root) {
        return 0;
    }
    if (!root->firstChild) {
        return 1;
    }
    int width = 0;
    Node* sibling = root->firstChild;
    while (sibling) {
        width++;
        sibling = sibling->nextSibling;
    }
    sibling = NULL;
    return max(width, getWidth(root->firstChild));
}

void deleteRoot(Node* root) {
    if (root == NULL){
        return;
    }
    deleteRoot(root->firstChild);
    deleteRoot(root->nextSibling);
    free(root);
}

void print_menu() {
    printf("What do you want to do?\n");
    printf("1: Add a node\n");
    printf("2: Print a tree\n");
    printf("3: Find a tree's width\n");
    printf("4: Delete node\n");
    printf("5: Exit\n");
    printf(">");
}

int main() {
    Node* root = NULL;
    int variant;
    print_menu();
    scanf("%d", &variant);
    while (variant != 5){
        switch(variant) {
            case 1: 
                addNode(&root);
                break;
            case 2:
                printf("Tree:\n");
                printTree(root, 0);
                break;
            case 3:
                printf("Max width of the tree: %d\n", getWidth(root));
                break;
            case 4:
                float data;
                printf("Enter the node data to delete: ");
                scanf("%f", &data);
                Node *parent = findNode(root, data);
                Node* grandparent = findNode2(root, data);
                if (grandparent == NULL) {
                    break;
                }
                if (grandparent->firstChild == parent) {
                    Node* reserve1 = parent->firstChild;
                    if (parent->nextSibling != NULL) {
                        reserve1 = parent->nextSibling;
                        deleteRoot(parent->firstChild);
                        grandparent->firstChild = reserve1;
                        free(parent);
                        parent = NULL;
                    }
                    else {
                        deleteRoot(parent);
                        parent = NULL;
                        grandparent->firstChild = reserve1;
                    }
                }
                else if (grandparent->nextSibling == parent) {
                    Node* reserve1 = parent->nextSibling;
                    deleteRoot(parent);
                    parent = NULL;
                    grandparent->nextSibling = reserve1;
                }
                else if (grandparent == parent) {
                    deleteRoot(parent);
                    parent = NULL;
                    grandparent = NULL;
                    root = NULL;
                }
                break;
        }
        print_menu();
        scanf("%d", &variant);
    }
    printf("Работа программы окончена\n");
    deleteRoot(root);
    return 0;
}