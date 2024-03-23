# Отчёт по лабораторной работе №23

---

## по курсу "Алгоритмы и структуры данных"


Студент группы М8О-108Б-23 Романов Вадим Михайлович

Работа выполнена

Преподаватель: каф.806 Севастьянов Виктор Сергеевич
1. Тема: Динамические структуры данных. Обработка деревьев.
2. Цель работы: составить программу на языке Си для построения и обработки дерева общего вида или упорядоченного двоичного дерева, содержащего узлы типа float.
3. Задание: определить ширину дерева.
4. Идея, метод, алгоритм решения задачи: 
Вроде как всё должно быть просто: всего лишь надо приспособить код из образца под свои нужды и дополнить его всеми необходимыми функциями согласно требованиям. Но это не так легко на самом деле. Нужно понять, как работает системы ссылок в Си, что невероятно сложно, но вроде бы мне понять из этого что-то удалось.
5. Сценарий выполнения работы:
- составить тип данных узла дерева и функцию по его созданию;
- составить функцию добавления сына и печати дерева;
- наконец-то выполнить само задание, составить функцию по нахождению ширины дерева;
- не забыть про функцию удаления дерева (плохо, что только под конец вспомнил);
И, конечно же, каждый этап работы сопровождался длительной и мучительной отладкой(вспомнить этот кошмар мне не по силам).
6. Протокол:
```c
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

void findWidth(Node* root, int level, int* width) {
    if (root == NULL) {
        return;
    }
    width[level]++;
    findWidth(root->firstChild, level + 1, width);
    findWidth(root->nextSibling, level, width);
}

void deleteNode(Node* root) {
    if (root == NULL){
        return;
    }
    deleteNode(root->firstChild);
    deleteNode(root->nextSibling);
    free(root);
}

int main() {
    Node* root = createNode(1.0);
    addChild(root, 2.0);
    addChild(root, 3.0);
    addChild(root->firstChild, 4.0);

    printf("Tree:\n");
    printTree(root, 0);

    int width[100] = {0};
    findWidth(root, 0, width);

    printf("Tree's width:\n");
    for (int i = 0; i < 100; i++) {
        if (width[i] > 0) {
            printf("Level %d: %d nodes\n", i, width[i]);
        }
    }

    deleteNode(root);

    return 0;
}
``` 
8. Выводы: впервые за всё время я просрочил дедлайн на 5. Это произошло из-за сноса Windows при запуске Makefile за минуту до сдачи лабы. Что ж, теперь я знаю, что нельзя лишний раз лезть в ядро ОС, если не хочешь получить порцию седины на голову. Сама программа с горем пополам заработала, а с Makefile-ами я теперь предельно осторожен и лишний раз не трогаю.