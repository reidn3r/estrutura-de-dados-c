#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

Node *Initialize(Node *root){
    root = NULL;
    return root;
}

Node *Insert(Node *root, Register x){
    if(root == NULL){
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode -> reg = x;
        newNode -> left = NULL;
        newNode -> right = NULL;
        return newNode;
    }
    else{
        if(x.key < root->reg.key){
            root -> left = Insert(root->left, x);
        }
        else if(x.key > root->reg.key){
            root -> right = Insert(root -> right, x);
        }
        return root;
    }
}

void InOrdem(Node *root){
    if(root != NULL){
        InOrdem(root -> left);
        printf("%d ", root -> reg.key);
        InOrdem(root -> right);
    }
}

void PreOrdem(Node *root){
    if(root != NULL){
        printf("%d ", root -> reg.key);
        PreOrdem(root -> left);
        PreOrdem(root -> right);
    }
}

void PosOrdem(Node *root){
    if(root != NULL){
        PosOrdem(root -> left);
        PosOrdem(root -> right);
        printf("%d ", root -> reg.key);
    }
}

void Conta(Node *root, int *cont){
    if(root != NULL){
        Conta(root -> left, cont);
        *cont = *cont+1;
        Conta(root -> right, cont);
    }
}

//Exercício 1
void Minimo(Node *root, int *min){
    if(root != NULL){
        if(*min == 0){
            *min = root -> reg.key;
            Minimo(root -> left, min);
        }
        else{
            if(root -> reg.key < *min){
                *min = root -> reg.key;
                Minimo(root -> left, min);
            }
        }
    }
}

//Exercício 2
void Maximo(Node *root, int *max){
    if(root != NULL){
        if(*max == 0){
            *max = root -> reg.key;
            Maximo(root -> right, max);
        }
        else{
            if(root -> reg.key > *max){
                *max = root -> reg.key;
                Maximo(root -> right, max);
            }
        }
    }
}

//Exercício 3.
void ArvoreArray(Node *root, int *arr, int *idx){
    if(root != NULL){
        ArvoreArray(root -> left, arr, idx);
        arr[*idx] = root -> reg.key;
        *idx = *idx +1;
        ArvoreArray(root -> right, arr, idx);
    }
}