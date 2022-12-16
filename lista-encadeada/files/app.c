#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(){
    Lista l1;
    int opc, x, index;
    inicializaLista(&l1);

    do{
        printf("(0) Imprime lista.\n");
        printf("(1) Add no final.\n");
        printf("(2) Add no inicio\n");
        printf("(3) Remove Final.\n");
        printf("(4) Remove Inicio\n");
        printf("(5) Substituir Elemento\n");
        printf("(6) Obter elemento.\n");
        printf("(7) Obter Numero de Ocorrencias.\n");
        printf("(8) Obter Ultimo Elemento.\n");
        printf("(9) Limpar Lista.\n");
        printf("(10) Remove Primeira Ocorrencia de x.\n");

        scanf("%d", &opc);

        if(opc==0){
            print(&l1);
        }

        if(opc==1){
            printf("x: ");
            scanf("%d", &x);
            addFinal(x, &l1);
        }
        if(opc==2){
            printf("x: ");
            scanf("%d", &x);
            addInicio(x, &l1);
        }
        if(opc==3){
            removeFinal(&l1);
        }

        if(opc==4){
            removeInicio(&l1);
        }

        if(opc==5){
            printf("index: ");
            scanf("%d", &index);
            printf("x: ");
            scanf("%d", &x);
            substituiElemento(index, x, &l1);
        }

        if(opc == 6){
            printf("index: ");
            scanf("%d", &index);
            printf("result: %d\n", obtemElemento(index, &l1));
        }

        if(opc==7){
            printf("x: ");
            scanf("%d", &x);
            printf("qtde.: %d\n", obterNumeroOcorrencias(x, &l1));
        }

        if(opc == 8){
            printLast(&l1);
        }

        if(opc == 9){
           limparLista(&l1); 
        }

        if(opc == 10){
            printf("x: ");
            scanf("%d", &x);
            removeP(x, &l1);
        }
    }
    while(opc >= 0);
    return 0;
}