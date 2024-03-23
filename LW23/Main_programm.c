#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    float data;
    struct Node* firstChild;
    struct Node* nextSibling;
} Node;

Node* createNode(float data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->firstChild = NULL;
    newNode->nextSibling = NULL;
    return newNode;
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

void addChild(Node* parent, float data) {
    Node* newChild = createNode(data);
    if (parent->firstChild == NULL) {
        parent->firstChild = newChild;
    } else {
        Node* sibling = parent->firstChild;
        while (sibling->nextSibling != NULL) {
            sibling = sibling->nextSibling;
        }
        sibling->nextSibling = newChild;
    }
}

void deleteNode(Node* root) {
    if (root == NULL){
        return;
    }
    deleteNode(root->firstChild);
    deleteNode(root->nextSibling);
    free(root);
}

void findWidth(Node* root, int level, int* width) {
    if (root == NULL) {
        return;
    }
    width[level]++;
    findWidth(root->firstChild, level + 1, width);
    findWidth(root->nextSibling, level, width);
}

int main() {
    Node* root = createNode(1.0);
    addChild(root, 2.0);
    addChild(root, 3.0);
    addChild(root->firstChild, 4.0);
    addChild(root->firstChild->nextSibling, 5.0);

    printf("Дерево:\n");
    printTree(root, 0);

    int width[100] = {0};
    findWidth(root, 0, width);

    printf("Ширина дерева:\n");
    for (int i = 0; i < 100; i++) {
        if (width[i] > 0) {
            printf("Уровень %d: %d узлов\n", i, width[i]);
        }
    }

    deleteNode(root);

    return 0;
}