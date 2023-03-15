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

Node *Initialize(Node *root);

Node *Insert(Node *root, Register x);

void InOrdem(Node *root);

void PreOrdem(Node *root);

void PosOrdem(Node *root);

void Conta(Node *root, int *cont);

//Exercício 1
void Minimo(Node *root, int *min);

//Exercício 2
void Maximo(Node *root, int *max);

//Exercício 3
void ArvoreArray(Node *root, int *arr, int *idx);

#endif