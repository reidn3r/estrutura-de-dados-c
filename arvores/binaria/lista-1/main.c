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
    }while(opc > 0);

    /* SEGUNDA ARVORE */
    printf("\nSEGUNDA ARVORE.\n");
    int opcao;
    Register r;
    Node *B = Initialize(B);
    do{
        printf("\n1) Insert.\n");
        scanf("%d", &opcao);
        if(opcao == 1){
            printf("key: ");
            scanf("%d", &r.key);
            B = Insert(B, r);
        }
    }while(opcao > 0);

    /* 
        - Compara e verifica se as arvores sao iguais
        - Implementação do exercício 4 da lista 1
    */
    int diferentes=0;
    Compara(root, B, &diferentes);
    if(!diferentes){
        printf("arvores iguais.\n");
    }
    else{
        printf("arvores diferentes.\n");
    }

    return 0;
}