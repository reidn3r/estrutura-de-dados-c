#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main(){
    TipoFila fila;
    TipoItem x;
    int key;
    int opc=0;

    FFVazia(&fila);

    do{
        printf("1) Enfileirar.\n");
        // printf("2) Print.\n");
        
        scanf("%d", &opc);

        if(opc == 1){
            printf("chave: ");
            scanf("%d", &x.chave);
            Enfileirar(&fila, x);
        }

        // else if(opc == 2){
        //     PrintFila(&fila);
        // }

    }while(opc > 0);

    /*
        Implementação do exercício 3
    */
    TipoFila fila_inv;
    fila_inv = InverteFila(&fila);
    printf("Fila invertida:\n");
    PrintFila(&fila_inv);
    
    return 0;
}