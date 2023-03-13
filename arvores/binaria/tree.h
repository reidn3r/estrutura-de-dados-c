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

void Initialize(Tree *T);

void Insert(Tree *tree, Register x);

void InOrdem(Node *root);

#endif