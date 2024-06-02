#ifndef tree_h
#define tree_h
typedef struct _b_node {
    int d_data;
    char s_data;
    struct _b_node* left;
    struct _b_node* right;
} Node;

typedef struct tree {
    Node* root;
} Tree;

Node* sign_create(char sign);
Node* number_create(float data);
Node* number_insert(Node* root, float data);
Node* sign_insert(Node* root, char sign);
void deleteRoot(Node* root);
void printTree(Node *root, int space);
void clear1 (char string[], int j);
void clear2 (char string[]);
int eq(int buf);
int FindNumber(char mono[]);
int FindDegree(char mono[]);
char FindSign(char mono[]);
void Add(Node* reserve, Node* root);
Node* addToTree(Node* root, char mono[], int k);
void clear(char expression[]);
void CountAnExpression(Node* root);

#endif