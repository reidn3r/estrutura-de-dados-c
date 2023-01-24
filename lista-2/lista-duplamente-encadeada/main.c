#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

int main(){
    TipoLista lista;
    TipoItem x;
    int opc=0;

    FLVazia(&lista);

    do{
        printf("1) Insert.\n");
        printf("2) Print.\n");
        printf("3) Print reverso.\n");
        printf("4) Insere Inicio.\n");
        printf("5) Remove Final.\n");
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

        else if(opc == 2){
            Print(&lista);
        }

        else if(opc == 3){
            PrintREV(&lista);
        }

        else if(opc == 4){
            printf("key: ");
            scanf("%d", &x.chave);

            printf("nome: ");
            scanf("%s", &x.nome);
            
            printf("idade: ");
            scanf("%d", &x.idade);

            InsereInicio(&lista, x);
        }

        else if(opc == 5){
            RemoveFinal(&lista);
        }

    }while(opc > 0);

    return 0;
}