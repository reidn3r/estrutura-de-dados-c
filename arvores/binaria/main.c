#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main(){

    int opc;
    Register x;
    Tree T;
    Initialize(&T);

    do{
        printf("\n1) Insert.\n");
        printf("2) In Ordem.\n");
        scanf("%d", &opc);

        if(opc == 1){
            printf("key: ");
            scanf("%d", &x.key);
            Insert(&T, x);
        }
        else if(opc == 2){
            InOrdem(T.root);
        }
    }while(opc > 0);

    return 0;
}