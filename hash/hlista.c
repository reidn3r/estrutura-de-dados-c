#include "hash.h"
#include <stdio.h>
#include <stdlib.h>

void FLVazia (TipoLista *Lista){
    Lista -> Primeiro = (Celula*) malloc(sizeof(Celula));
    Lista -> Ultimo = Lista -> Primeiro;
    Lista -> Primeiro -> Prox = NULL;
}

void Insere (TipoItem x, TipoLista *Lista){
    Lista -> Ultimo -> Prox = (Celula*) malloc(sizeof(Celula));
    Lista -> Ultimo = Lista -> Ultimo -> Prox;
    Lista -> Ultimo -> Item = x;
    Lista -> Ultimo -> Prox = NULL;
}

void Imprime (TipoLista *lista){
    Celula *aux = (Celula*)malloc(sizeof(Celula));
    aux = lista -> Primeiro;
    while(aux -> Prox != NULL){
        printf("dado: %c\n", aux->Prox->Item.data);
        aux = aux -> Prox;
    }
    printf("\n");
}

//Funções Tabela Hash

TipoLista *THash(int size){
    int i=0;
    TipoLista *array = (TipoLista *)malloc(size * sizeof(TipoLista));
    for(i; i<size; i++){
        FLVazia(&array[i]);
    }

    /*
    Teste:

    i=0;
    for(i; i<size; i++){
        if(array[i].Primeiro -> Prox == NULL){
            printf("idx: %d - NULL\n", i);
        }
    }
    */
    return array;
}

void ImprimeTHash(TipoLista *array, int size){
    int i=0;
    for(i; i<size; i++){
        if(array[i].Primeiro != array[i].Ultimo){
            printf("idx: %d\n", i);
            Imprime(&array[i]);
        }
    }
}