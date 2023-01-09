#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    int opc;
    TipoLista lista;
    TipoItem x;
    FLVazia(&lista);

    do{

        printf("1. Insere\n");
        printf("2. Conta\n");
        printf("3. Imprime\n");
        scanf("%d", &opc);

        if(opc == 1){
            printf("Chave: ");
            scanf("%i", &x.chave);

            printf("Nome: ");
            scanf("%s", &x.nome);

            printf("Idade: ");
            scanf("%i", &x.idade);

            Insere(&lista, x);
        }

        else if(opc == 2){
            Conta(&lista);
        }

        else if(opc == 3){
            Imprime(&lista);
        }
    }
    while(opc>0);

    return 0;
}
