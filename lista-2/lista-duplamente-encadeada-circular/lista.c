#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

void FLVazia(TipoLista *lista){
    lista -> Primeiro = NULL;
}

void InsereFinal(TipoLista *lista, TipoItem x){
    if(lista->Primeiro == NULL){
        lista->Primeiro = (Celula*)malloc(sizeof(Celula));
        lista->Primeiro->item = x;
        lista->Primeiro->Prox = lista->Primeiro;
        lista->Primeiro->Ant = NULL;
    }
    else{
        Celula *aux = lista -> Primeiro;
        while(aux->Prox != NULL){
            aux = aux -> Prox;
        }
        Celula *Item = (Celula*)malloc(sizeof(Celula));
        Item -> item = x;
        Item -> Prox = lista -> Primeiro;

        aux -> Prox = Item;
        Item -> Ant = aux;
    }
}

void Print(TipoLista *lista){
    if(lista->Primeiro == NULL){
        printf("Lista vazia.\n");
    }
    else{
        Celula *aux = lista -> Primeiro;
        printf("chave: %d\n", aux->item.chave);
        printf("nome: %s\n", aux->item.nome);
        printf("idade: %d\n", aux->item.idade);
        printf("\n");

        while(aux != lista -> Primeiro){
            printf("chave: %d\n", aux->item.chave);
            printf("nome: %s\n", aux->item.nome);
            printf("idade: %d\n", aux->item.idade);
            printf("\n");
            aux = aux -> Prox;
        }
    }
}
