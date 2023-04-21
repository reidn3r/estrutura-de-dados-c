#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

Node *Initialize(Node *root){
    //root points to NULL
    root = NULL;
    return root;
}

Node *Insert(Node *root, Register x){
    /*
        - Params: root and register
        - Return: root (the same as parameter)
    */
    if(root == NULL){
        return newNode(x);
    }
    else{
        if(x.key < root -> reg.key){
            root -> left = Insert(root -> left, x);
        }
        else if(x.key > root -> reg.key){
            root -> right = Insert(root -> right, x);
        }
        else{
            printf("valor ja inserido.\n");
        }
        root -> height = greater(nodeHeight(root -> left), nodeHeight(root -> right)) + 1;
        root = balance(root);

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

//AVL
Node *newNode(Register x){
    Node *newNode = (Node *)malloc(sizeof(Node));
    if(newNode){
        newNode -> reg = x;
        newNode -> left = NULL;
        newNode -> right = NULL;
        newNode -> height = 0;
    }
    else{
        printf("No memory available.\n");
    }
    return newNode;
}

int greater(int a, int b){
    return(a>b) ? a : b;
}

int nodeHeight(Node *node){
    if(node == NULL){
        return -1;
    }
    else{
        return node -> height;
    }
}

int balanceFactor(Node *node){
    /*
        FB = height sub. arvore esquerda - height sub. arvore direita
        Se |FB| > 1, arvore desbalanceada
    */
    if(node){
        return (nodeHeight(node -> left) - nodeHeight(node -> right));
    }
    else{
        return 0;
    }
}

// Rotations
Node *leftRotation(Node *root){
    // bf < -1
    Node *y, *f;
    y = root -> right;
    f = root -> left;

    y -> left = root;
    root -> right = f;

    root -> height = greater(nodeHeight(root -> left), nodeHeight(root -> right)) + 1;
    y -> height = greater(nodeHeight(y -> left), nodeHeight(y -> right)) + 1;
    return y;
}

Node *rightRotation(Node *root){
    //bf > 1
    Node *y, *f;
    y = root -> left;
    f = y -> right;

    y -> right = root;
    root -> left = f;

    root -> height = greater(nodeHeight(root -> left), nodeHeight(root -> right)) + 1;
    y -> height = greater(nodeHeight(y -> left), nodeHeight(y -> right)) + 1;
    
    return y;
}

Node *doubleRightRotation(Node *root){
    root -> right = rightRotation(root -> right);
    return leftRotation(root);
}

Node *doubleLeftRotation(Node *root){
    root -> left = leftRotation(root -> left);
    return rightRotation(root);
}

Node *balance(Node *root){
    int bf = balanceFactor(root);

    //Left
    if(bf < -1 && balanceFactor(root -> right) <= 0){
        root = leftRotation(root);
    }

    //Right
    else if(bf > 1 && balanceFactor(root -> left) >= 0){
        root = rightRotation(root);
    }

    //Double Left
    else if(bf > 1 && balanceFactor(root -> left) < 0){
        root = doubleLeftRotation(root);
    }

    //Double Right
    else if(bf < -1 && balanceFactor(root -> right) > 0){
        root = doubleRightRotation(root);
    }

    return root;
}