#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    if (a >= b) {
        return a;
    }
    return b;
}

typedef struct Node {
    float data; // Теперь данные узла имеют тип float
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
    printf("%.2f\n", root->data); // Форматированный вывод для типа float
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
        exit(1); // Или обработайте ошибку по-другому
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

void deleteNode(Node* root) {
    if (root == NULL){
        return;
    }
    deleteNode(root->firstChild);
    deleteNode(root->nextSibling);
    free(root);
}

void print_menu() {
    system("cls");
    printf("What do you want to do?\n");
    printf("1: Create a root\n");
    printf("2: Add a child\n");
    printf("3: Print a tree\n");
    printf("4: Find a tree's width\n");
    printf("5: Delete node\n");
    printf("6: Exit\n");
    printf(">");
}

int get_variant() {
    int variant;
    char s[5];
    scanf("%s", s);

    while (sscanf(s, "%d", &variant) != 1 || variant < 1 || variant > 6) {
        printf("Incorrect input. Try again: "); 
        scanf("%s", s);
    }

    return variant;
}



int main() {
    int variant;
    float data;
    char str_node;
    int level;
    while (variant != 6) {
        print_menu();
        variant = get_variant();
        switch (variant) {
            case 1:
                printf("Enter a float number: ");
                scanf("%f\n", &data);
                Node* root = createNode(data);
                break;
            case 2:
                printf("Enter the parent node: ");
                scanf(" %c", &str_node);
                Node *parent = root;
                Node *newNode;
                printf("Enter the data for the new node: ");
                scanf("%d", &data);
                addChild(parent, data);
            case 3:
                printf("Enter a level: ");
                scanf("%d", &level);
                printf("Enter the node: ");
                scanf("%c", &str_node);
                struct Node *parent = scanf("%s", parent);
                printTree(parent, level);
            case 4:
                int width[100] = {0};
                int maxwidth = 0;
                findWidth(root, 0, width);
                for (int i = 0; i < 100; i++) {
                    if (width[i] > 0) {
                    maxwidth = max(maxwidth, width[i]);
                    }
                }
                printf("Max width = %d nodes.", maxwidth);
            case 5:
                printf("Enter a node: ");
                scanf("%20s", str_node);
                struct Node *parent = scanf("%s", parent);
                deleteNode(parent);
        }
        if (variant != 6) {
            system("pause");
        }
    }
    return 0;
}