#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main(){

    int opc;
    Register x;
    Tree T;
    Initialize(&T);
    
    int s=0;

    do{
        printf("\n1) Insert.\n");
        printf("2) In Ordem.\n");
        printf("3) Pre Ordem.\n");
        printf("4) Pos Ordem.\n");
        printf("5) Conta.\n");
        scanf("%d", &opc);

        if(opc == 1){
            printf("key: ");
            scanf("%d", &x.key);
            Insert(&T, x);
        }
        else if(opc == 2){
            printf("\n");
            InOrdem(T.root);
        }

        else if(opc == 3){
            printf("\n");
            PreOrdem(T.root);
        }

        else if(opc == 4){
            printf("\n");
            PosOrdem(T.root);
        }

        else if(opc == 5){
            Conta(T.root, &s);
            printf("cont: %d\n", s);
        }

    }while(opc > 0);

    return 0;
}