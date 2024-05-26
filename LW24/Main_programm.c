#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct _b_node {
    float d_data;
    char s_data;
    struct _b_node* parent;
    struct _b_node* left;
    struct _b_node* right;
} Node;

typedef struct tree {
    Node* root;
} Tree;

Node* sign_create(char sign) {
    Node* node = (Node* )malloc(sizeof(Node));
    node->s_data = sign;
    node->d_data = INT_MAX;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* number_create(float data) {
    Node* node = (Node* )malloc(sizeof(Node));
    node->s_data = '\n';
    node->d_data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}/*И это походу тоже не надо, но пока оставлю*/

Node* number_insert(Node* root, float data) {
    if (root == NULL) {
        return number_create(data);
    }/*Это нам вообще не надо, всю структуру дерева рушит, но всё же добавил*/
    root->d_data = data;
    root->s_data = '\n';
    root->left = NULL;
    root->right = NULL;
    return root;
}

Node* sign_insert(Node* root, char sign) {
    if (root == NULL) {
        return sign_create(sign);
    }

    root->d_data = INT_MAX;
    root->s_data = sign;
    root->left = NULL;
    root->right = NULL;
    return root;
}

void deleteRoot(Node* root) {
    if (root == NULL){
        return;
    }
    deleteRoot(root->left);
    deleteRoot(root->right);
    free(root);
}

void printTree(Node *root, int level) { 
    if (root == NULL) { 
        return; 
    }  
 
    printTree(root->right, level + 1); 
 
    printf("\n"); 
    for (int i = 0; i < level; i++) { 
        printf("  "); 
    } 
 
    if (root->s_data == '\n') {
        printf("%f", root->d_data);
    } 
    else {
        printf("%c", root->s_data);
    }
 
    printTree(root->left, level + 1); 
}


void clear1 (char string[], int j){
    while (j < 9)
    {
        string[j] = ' ';
        j++;
    }
}


void clear2 (char string[]){
    for (int i = 0; i < 9; i++){
        string[i] = ' ';
    }
}


void addToTree(char mono[]){
    int j = 0, check = 0, number = 0;
    while (check == 0){
        for (int i = 0; i <= 9; i++){
            int buf = mono
            if (int(mono[j]) == i){
                check = 1;
            }
            if (check == 1) {
                number = number * 10 + (mono[j]);
            }
            else {
                break;
            }
            check = 0;
        } 
    }
}


int main() {
    Node *root = NULL;
    char expression[100], mono[10];
    int check = 0, i = 0;
    fgets(expression, 100, stdin);
    while (expression[i] != '\n'){
        int j = 0;
        while (((expression[i] != '+') && (expression[i] != '-')) && (j < 10)){
            if (expression[i] == '\n') {
                break;
            }
            if (expression[i] != ' '){
                mono[j] = expression[i];
                j++;
            }
            i++;
        }
        if (expression[i] == '+'){
            mono[j] = '+';
        }
        else if (expression[i] == '-'){
            mono[j] = '-';
        }
        clear1(mono, j + 1);
        addToTree(mono);
        printf("%s\n", mono);
        clear2(mono);
        if (expression[i] == '\n') {
            break;
        }
        i++;
    }
    root = sign_insert(root, '+');
    printTree(root, 0);
    deleteRoot(root);
}