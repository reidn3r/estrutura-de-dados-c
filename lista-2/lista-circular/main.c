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
        printf("3) Contagem.\n");
        scanf("%d", &opc);

        if(opc == 1){
            printf("key: ");
            scanf("%d", &x.chave);

            printf("nome: ");
            scanf("%s", &x.nome);
            
            printf("idade: ");
            scanf("%d", &x.idade);

            Insere(&lista, x);
        }

        if(opc == 2){
            Print(&lista);
        }

        if(opc == 3){
            Conta(&lista);
        }
    }while(opc > 0);

    //Implementação do ex.2
    printf("\n\nCopia da lista:\n");
    TipoLista lista_2 = CopiaLista(&lista);
    Print(&lista_2);

    return 0;
}