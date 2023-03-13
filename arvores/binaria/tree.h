#ifndef TREE_H
#define TREE_H

typedef struct{
    int key;
}Register;

typedef struct Node{
    Register reg;
    struct Node *left;
    struct Node *right;
}Node;

typedef struct Tree{
    Node *root;
}Tree;

Node *Initialize(Node *root);

// void Insert(Tree *tree, Register x);

Node *Insert(Node *root, Register x);

void InOrdem(Node *root);

void PreOrdem(Node *root);

void PosOrdem(Node *root);

void Conta(Node *root, int *cont);

#endif