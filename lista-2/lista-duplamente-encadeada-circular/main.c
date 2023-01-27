#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(){
    TipoLista lista;
    TipoItem x;
    int opc=0;

    FLVazia(&lista);

    do{
        printf("1) Insert.\n");
        printf("2) Print.\n");
        scanf("%d", &opc);

        if(opc == 1){
            printf("key: ");
            scanf("%d", &x.chave);

            printf("nome: ");
            scanf("%s", &x.nome);
            
            printf("idade: ");
            scanf("%d", &x.idade);

            InsereFinal(&lista, x);
        }

        else if(opc == 2){
            Print(&lista);
        }
        
        //Ex. 5 ...
        else if(opc == 3){
            RemoveInicio(&lista);
        }

    }while(opc > 0);
    
    return 0;
}