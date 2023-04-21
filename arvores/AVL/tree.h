#ifndef AVL_TREE
#define AVL_TREE

typedef struct{
    int key;
}Register;

typedef struct Node{
    struct Node *left;
    struct Node *right;
    Register reg;
    int height;
}Node;

Node *Initialize(Node *root);

Node *Insert(Node *root, Register x);

Node *newNode(Register x);

void InOrdem(Node *root);


//Funções auxiliares
int greater(int a, int b);

Node *newNode(Register x);

int greater(int a, int b);

int nodeHeight(Node *node);

//AVL + Rotacoes + Balancemanto
int balanceFactor(Node *node);

Node *leftRotation(Node *root);

Node *rightRotation(Node *root);

Node *doubleRigthRotation(Node *root);

Node *doubleLeftRotation(Node *root);

Node *balance(Node *root);

#endif