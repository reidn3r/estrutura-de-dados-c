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
        lista->Primeiro->Ant = lista->Primeiro;
        lista->Primeiro->Ant = NULL;
    }
    else{
        Celula *aux = lista -> Primeiro;
        while(aux->Prox != lista -> Primeiro){
            aux = aux -> Prox;
        }
        Celula *Item = (Celula*)malloc(sizeof(Celula));
        Item -> item = x;

        Item -> Prox = lista -> Primeiro;
        Item -> Ant = aux;

        aux -> Prox = Item;
        lista -> Primeiro -> Ant = Item;
    }
}

void RemoveInicio(TipoLista *lista){
    // if(lista -> Primeiro == NULL){
    //     printf("Lista vazia.\n");
    // }
    // else{
    //     Celula *aux = lista -> Primeiro -> Prox;
    //     aux -> Ant = lista -> Primeiro -> Ant;
    //     free(aux -> Ant);
    //     lista -> Primeiro = aux;
    //     while(aux -> Prox != Lista -> Primeiro){
    //         aux = aux -> Prox;
    //     }
    //     aux -> Prox = lista -> Primeiro;
    // }

    // /*
    //     Remover o ultimo?
    // */
    return NULL;
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

        while(aux -> Prox != lista -> Primeiro){
            aux = aux -> Prox;
            printf("chave: %d\n", aux->item.chave);
            printf("nome: %s\n", aux->item.nome);
            printf("idade: %d\n", aux->item.idade);
            printf("\n");
        }
    }
}
