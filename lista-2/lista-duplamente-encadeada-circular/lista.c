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

//Ex. 5
void RemoveInicio(TipoLista *lista){
    if(lista -> Primeiro == NULL){
        printf("Lista vazia.\n");
    }
    else{
        Celula *aux = lista -> Primeiro -> Prox;
        lista -> Primeiro -> Ant -> Prox = aux;
        aux -> Ant = lista -> Primeiro -> Ant;

        /*
            * Caso lista->Primeiro == aux (lista só tem 1 célula):
                - Desaloca memória de lista -> Primeiro e aponta pra NULL
                - Se não, aponta pra aux.
        */
        if(lista -> Primeiro == aux){
            free(lista -> Primeiro);
            lista -> Primeiro = NULL;
        }
        else{
            free(lista -> Primeiro);
            lista -> Primeiro = aux;
        }
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

        while(aux -> Prox != lista -> Primeiro){
            aux = aux -> Prox;
            printf("chave: %d\n", aux->item.chave);
            printf("nome: %s\n", aux->item.nome);
            printf("idade: %d\n", aux->item.idade);
            printf("\n");
        }
    }
}
