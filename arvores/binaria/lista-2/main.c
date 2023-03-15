#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main(){

    int opc;
    Register x;
    Node *root = Initialize(root);    

    do{
        printf("\n1) Insert.\n");
        printf("2) In Ordem.\n");
        printf("3) Pre Ordem.\n");
        printf("4) Pos Ordem.\n");
        printf("5) Conta.\n");
        printf("6) Minimo.\n");
        printf("7) Maximo.\n");
        scanf("%d", &opc);

        if(opc == 1){
            printf("key: ");
            scanf("%d", &x.key);
            root = Insert(root, x);
        }
        else if(opc == 2){
            printf("\n");
            InOrdem(root);
        }

        else if(opc == 3){
            printf("\n");
            PreOrdem(root);
        }

        else if(opc == 4){
            printf("\n");
            PosOrdem(root);
        }

        else if(opc == 5){
            int s=0;
            Conta(root, &s);
            printf("cont: %d\n", s);
        }

        //Exercício 1 da lista 2
        else if(opc == 6){
            int min = 0;
            Minimo(root, &min);
            if(root != NULL){
                printf("minimo: %d\n", min);
            }
            else{
                printf("arvore vazia.\n");
            }
        }

        //Exercício 2 da lista 2
        else if(opc == 7){
            int max = 0;
            Maximo(root, &max);
            if(root != NULL){
                printf("maximo: %d\n", max);
            }
            else{
                printf("arvore vazia.\n");
            }
        }
}while(opc > 0);

    //Exercício 3.

    /*
        1. size: variável útil para determinar o tamanho do vetor com a função Conta
        2. idx: variável utilizada como índice do vetor alocado dinamicamente
            - Ambas devem ser inicializadas em 0
    */
    int size=0, idx=0;
    Conta(root, &size);

    //Vetor alocado dinamicamente
    int *arr = (int *)malloc(size * sizeof(int));
    ArvoreArray(root, arr, &idx);

    printf("Array:\n[ ");
    int i=0;
    for(i; i<size; i++){
        printf("%d ", *(arr + i));
    }
    printf("]");

    return 0;
}