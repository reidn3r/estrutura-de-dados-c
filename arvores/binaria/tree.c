#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

void Initialize(Tree *T){
    T -> root = NULL;
}

void LeftInsert(Node *node, Register x){
    if(node -> left == NULL){
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode -> reg = x;
        newNode -> left = NULL;
        newNode -> right = NULL;
        node -> left = newNode;
    }
    else{
        if(x.key < node->left->reg.key){
            LeftInsert(node -> left, x);
        }
        else{
            LeftInsert(node -> right, x);
        }
    }
}

void RightInsert(Node *node, Register x){
    if(node -> right == NULL){
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode -> reg = x;
        newNode -> left = NULL;
        newNode -> right = NULL;
        node -> right = newNode;
    }
    else{
        if(x.key > node -> right -> reg.key){
            RightInsert(node -> right, x);
        }
        else{
            LeftInsert(node -> right, x);
        }
    }
}

void Insert(Tree *tree, Register x){
    if(tree -> root == NULL){
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode -> reg = x;
        newNode -> left = NULL;
        newNode -> right = NULL;
        tree -> root = newNode;
    }
    else{
        if(x.key < tree->root->reg.key){
            LeftInsert(tree -> root, x);
        }
        else{
            RightInsert(tree -> root, x);
        }
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