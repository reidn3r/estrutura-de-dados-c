#include <stdio.h>
#include <stdlib.h>
#include "../includes/fila.h"

int main(){
    TipoPilha pilha;
    TipoItem x;
    int key;
    int opc=0;

    FPVazia(&pilha);

    do{
        printf("valor<0) Sair .\n");
        printf("1) Empilhar.\n");
        printf("2) Print.\n");
        printf("3) Print na ordem inserida.\n");
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
        
        //Implementação do exercício 2
        else if(opc == 3){
            PrintREV(&pilha);
        }

        //Implementação do exercício 4
        else if(opc == 4){
            printf("chave: ");
            scanf("%d", &key);
            RemoveChave(&pilha, key);
        }
    }while(opc > 0);

    ApagaPilha(&pilha);
    
    return 0;
}