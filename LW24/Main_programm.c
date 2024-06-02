#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


typedef struct _b_node {
    int d_data;
    char s_data;
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

void printTree(Node *root, int space) { 
    if (root == NULL) { 
        return; 
    } 
 
    space += 5; 
 
    printTree(root->right, space); 
 
    printf("\n"); 
    for (int i = 5; i < space; i++) { 
        printf(" "); 
    } 
 
    if (root->d_data != INT_MAX){
        int buf = root->d_data;
        printf("%d", buf);
    }
    else{
        char buf = root->s_data;
        printf("%c", buf);
    } 
 
    printTree(root->left, space); 
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

int eq(int buf){
    if ((48 <= buf) && (buf <= 57)){
        buf = buf - 48;
        return buf;
    }
    return -1;
}

int FindNumber(char mono[]){
    int number = 0, i = 0;
    while((mono[i] != 'x') && (i <= 8)){
        int buf = mono[i];
        buf = eq(buf);
        if (buf != -1){
            number = number * 10 + buf;
        }
        i++;
    }
    if (number == 0){
        number = 1;
    }
    return number;
}

int FindDegree(char mono[]){
    int degree = 0, i = 0;
    while ((mono[i] != 'x') && (mono[i] != '+') && (mono[i] != '-') && (i <= 8)){
        i++;
    }
    i++;
    if ((mono[i] != '^') && (i != 10)){
        degree = 1;
        return degree;
    }
    if ((mono[i] == '+') || (mono[i] == '-') || (i == 10)){
        degree = 0;
        return degree;
    }
    i++;
    int buf = mono[i];
    while ((buf >= 48) && (buf <= 57)){
        degree = degree * 10 + (buf - 48);
        i++;
        buf = mono[i];
    }
    return degree;
}

char FindSign(char mono[]){
    int i = 0;
    for (i = 0; i <= 9; i++){
        if (mono[i] == '+'){
            return '+';
        }
        else if (mono[i] == '-'){
            return '-';
        }
    }
    return '\n';
}

void Add(Node* reserve, Node* root){
    while(reserve->right != NULL){
        reserve = reserve->right;
    }
    reserve->right = root;
}

Node* addToTree(Node* root, char mono[], int k){
    Node* reserve;
    int degree = 0, number = 0;
    char sign = '\n';
    number = FindNumber(mono);
    degree = FindDegree(mono);
    sign = FindSign(mono);
    if (sign != '\n'){
        root = sign_insert(root, sign);
        reserve = root;
        reserve->left = sign_insert(root->left, '*');
        reserve->left->left = sign_insert(root->left->left, '*');
        reserve->left->right = sign_insert(root->left->right, '^');
        reserve->left->left->left = number_insert(root->left->left->left, k);
        reserve->left->left->right = number_insert(root->left->left->right, number);
        reserve->left->right->left = sign_insert(root->left->right->left, 'x');
        reserve->left->right->right = number_insert(root->left->right->right, degree);
    }else{
        root = sign_insert(root, '*');
        reserve = root;
        reserve->left = sign_insert(root->left, '*');
        reserve->right = sign_insert(root->right, '^');
        reserve->left->left = number_insert(root->left->left, k);
        reserve->left->right = number_insert(root->left->right, number);
        reserve->right->left = sign_insert(root->right->left, 'x');
        reserve->right->right = number_insert(root->right->right, degree);
    }
    return root;
}

void clear(char expression[]){
    for (int i = 0; i < 99; i++){
        expression[i] = ' ';
    }
    return;
}

void CountAnExpression(Node* root){
    Node* current = root;
    Node* sign = root;
    char expression[100];
    clear(expression);
    int i = 0, j = 0;
    while (sign->s_data != '*'){
        j = 0;
        current = sign->left;
        int buf = (current->left->left->d_data) * (current->left->right->d_data);
        char buf2[5];
        snprintf(buf2, sizeof buf2, "%d", buf);
        while((buf2[j] == '0') || (buf2[j] == '1') || (buf2[j] == '2') || (buf2[j] == '3') || (buf2[j] == '4')
        || (buf2[j] == '5') || (buf2[j] == '6') || (buf2[j] == '7') || (buf2[j] == '8') || (buf2[j] == '9')){
            expression[i] = buf2[j]; // коэффициент
            i++;
            j++;
        }
        if (current->right->right->d_data != 0){
            expression[i] = current->right->left->s_data; //сам x
            i++;
        }
        if (current->right->right->d_data > 1){
            expression[i] = current->right->s_data; 
            i++;
            buf = current->right->right->d_data;
            snprintf(buf2, sizeof buf2, "%d", buf);
            j = 0;
            while((buf2[j] == '0') || (buf2[j] == '1') || (buf2[j] == '2') || (buf2[j] == '3') || (buf2[j] == '4')
            || (buf2[j] == '5') || (buf2[j] == '6') || (buf2[j] == '7') || (buf2[j] == '8') || (buf2[j] == '9')){
                expression[i] = buf2[j]; // степень
                i++;
                j++;
            }
        }
        expression[i] = ' ';
        i++;
        expression[i] = sign->s_data;
        i++;
        expression[i] = ' ';
        i++;
        sign = sign->right;
        current = sign;       
    }
    int buf = (current->left->left->d_data) * (current->left->right->d_data);
    char buf2[5];
    snprintf(buf2, sizeof buf2, "%d", buf);
    j = 0;
    while(j < 5){
        int buf3 = buf2[j];
        if ((48 <= buf3) && (buf3 <= 57)){
            expression[i] = buf2[j]; // коэффициент
        }
        i++;
        j++;
    }
    if (current->right->right->d_data != 0){
        expression[i] = current->right->left->s_data; //сам x
    }
    else if (current->right->right->d_data > 1){
        i++;
        expression[i] = current->right->s_data; 
        snprintf(buf2, sizeof buf2, "%d", current->right->right->d_data);
        j = 0;
        while((buf2[j] == '0') || (buf2[j] == '1') || (buf2[j] == '2') || (buf2[j] == '3') || (buf2[j] == '4')
        || (buf2[j] == '5') || (buf2[j] == '6') || (buf2[j] == '7') || (buf2[j] == '8') || (buf2[j] == '9')){
            expression[i] = buf2[j]; // степень
            i++;
            j++;
        }
    }
    printf("\n\nИтоговый многочлен: ");
    for (j = 0; j < i; j++){
        printf("%c", expression[j]);
    }
}


int main() {
    Node *root = NULL;
    Node *reserve = NULL;
    char expression[100], mono[11];
    int i = 0, k = 0, count = 0;
    printf("Введите многочлен: ");
    fgets(expression, 100, stdin);
    printf("Введите множитель: ");
    scanf("%d", &k);
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
        if (count >= 1){
            root = root->right;
        }
        root = addToTree(root, mono, k);
        count ++;
        if (count == 1){
            reserve = root;
        }
        else{
            Add(reserve, root);
        }
        clear2(mono);
        if (expression[i] == '\n') {
            break;
        }
        i++;
    }
    printTree(reserve, 5);
    CountAnExpression(reserve);
    deleteRoot(reserve);
}