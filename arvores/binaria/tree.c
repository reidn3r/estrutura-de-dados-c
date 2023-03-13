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
        else{
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