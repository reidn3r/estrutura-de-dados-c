#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main(){

    int opc;
    Register x;
    Node *root = Initialize(root);

    do{
        printf("\n1) Insert.\n");
        printf("2) InOrdem.\n");
        printf("opc: ");
        scanf("%d", &opc);

        if(opc == 1){
            printf("key: \n");
            scanf("%d", &x.key);
            root = Insert(root, x);
        }

        if(opc == 2){
            printf("\n");
            InOrdem(root);
        }

    }
    while(opc > 0);
    return 0;
}