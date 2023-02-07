#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"

void FPVazia(TipoPilha *pilha){
    pilha -> Topo = NULL;
    pilha -> Fundo = NULL;
    pilha -> Tamanho = 0;
}

void Empilha(TipoPilha *pilha, TipoItem x){
    Celula *aux = (Celula*)malloc(sizeof(Celula));
    aux -> item = x;
    if(pilha -> Topo == NULL){
        pilha -> Fundo = aux;
        aux -> Prox = pilha -> Topo;
        pilha -> Topo = aux;
    }
    else{
        aux -> Prox = pilha -> Topo;
        pilha -> Topo = aux;
        pilha->Tamanho++;
    }
}

void Desempilha(TipoPilha *pilha, TipoItem *Item){
    
    if(pilha -> Topo == NULL){
        printf("Pilha vazia\n");
    }
    else{
        Celula *aux = pilha -> Topo;
        pilha -> Topo = aux -> Prox;
        *Item = aux->item; //útil p/ desempilhar em outra pilha
        free(aux);

        pilha -> Tamanho --;
        if(pilha -> Tamanho == 0){
            pilha -> Fundo = pilha -> Topo;
        }
    }
}

void Print(TipoPilha *pilha){
    if(pilha -> Topo == NULL){
        printf("Pilha vazia\n");
    }
    else{
        Celula *aux = pilha -> Topo;
        while(aux != NULL){
            printf("chave: %d\n", aux -> item.chave);
            aux = aux -> Prox;
        } 
        printf("\n\n");
    }
}
void PrintREV(TipoPilha *pilha){

    if(pilha -> Topo == NULL){
        printf("Pilha vazia.\n");
    }
    else{
        TipoPilha pilha_copy;
        FPVazia(&pilha_copy);

        Celula *aux = pilha -> Topo;
        while(aux != NULL){
            Empilha(&pilha_copy, aux->item);
            aux = aux-> Prox;
        }
        Print(&pilha_copy);
    } 


}