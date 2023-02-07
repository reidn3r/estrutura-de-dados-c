#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main(){
    TipoPilha pilha;
    TipoItem x;
    int opc=0;

    FPVazia(&pilha);

    do{
        printf("1) Empilhar.\n");
        printf("2) Print.\n");
        printf("3) Print Reverso.\n");
        
        scanf("%d", &opc);

        if(opc == 1){
            printf("chave: ");
            scanf("%d", &x.chave);

            Empilha(&pilha, x);
        }

        if(opc == 2){
            Print(&pilha);
        }

        if(opc == 3){
            PrintREV(&pilha);
        }

    }while(opc > 0);
    
    return 0;
}