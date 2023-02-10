#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main(){
    TipoPilha pilha;
    TipoItem x;
    int key;
    int opc=0;

    FPVazia(&pilha);

    do{
        printf("1) Empilhar.\n");
        printf("2) Print.\n");
        printf("3) Print Reverso.\n");
        printf("4) Remover chave.\n");
        
        scanf("%d", &opc);

        if(opc == 1){
            printf("chave: ");
            scanf("%d", &x.chave);

            Empilha(&pilha, x);
        }

        else if(opc == 2){
            Print(&pilha);
        }

        else if(opc == 3){
            PrintREV(&pilha);
        }
        
        else if(opc == 4){
            printf("chave: ");
            scanf("%d", &key);
            RemoveChave(&pilha, key);
        }

    }while(opc > 0);
    
    return 0;
}