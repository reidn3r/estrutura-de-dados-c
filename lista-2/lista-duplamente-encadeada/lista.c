#include "lista.h"
#include <stdlib.h>
#include <stdio.h>

void FLVazia(TipoLista *lista){
    lista -> Primeiro = (Celula *)malloc(sizeof(Celula));
    lista -> Ultimo = lista -> Primeiro;
    lista -> Primeiro -> Prox = NULL;
    lista -> Primeiro -> Ant = NULL;
}

void Insere(TipoLista *lista, TipoItem x){
    lista -> Ultimo -> Prox = (Celula *)malloc(sizeof(Celula));
    lista -> Ultimo -> Prox -> Ant = lista -> Ultimo;
    lista -> Ultimo = lista -> Ultimo -> Prox;
    lista -> Ultimo -> item = x;
    lista -> Ultimo -> Prox = NULL;
}

//Ex. 3
void InsereInicio(TipoLista *lista, TipoItem x){
    Celula *Item = (Celula *)malloc(sizeof(Celula));
    Item -> item = x;
    if(lista -> Primeiro == lista -> Ultimo){
        Insere(lista, x);
    }
    else{
        Item -> Ant = lista -> Primeiro;
        Item -> Prox = lista -> Primeiro -> Prox;
        
        lista -> Primeiro -> Prox -> Ant = Item;
        lista -> Primeiro -> Prox = Item;
    }
    
}

//Ex. 4
void RemoveFinal(TipoLista *lista){
    if(lista -> Primeiro == lista -> Ultimo){
        printf("Lista vazia.\n");
    }
    else{
        Celula *aux = lista -> Ultimo -> Ant;
        aux -> Prox = NULL;
        free(lista -> Ultimo);
        lista -> Ultimo = aux;
    }
}

void Print(TipoLista *lista){
    if(lista->Primeiro == lista->Ultimo){
        printf("Lista vazia.\n");
    }
    else{
        Celula *aux = (Celula*)malloc(sizeof(Celula));
        aux = lista -> Primeiro;
        while(aux -> Prox != NULL){
            printf("chave: %d\n", aux->Prox -> item.chave);
            printf("nome: %s\n", aux->Prox -> item.nome);
            printf("idade: %d\n", aux->Prox -> item.idade);
            printf("\n");
            aux = aux -> Prox;
        }
    }
    printf("\n");
}

void PrintREV(TipoLista *lista){
    if(lista->Primeiro == lista->Ultimo){
        printf("Lista vazia.\n");
    }
    else{
        Celula *aux;
        aux = lista -> Ultimo;
        while(aux != lista -> Primeiro){
            printf("chave: %d\n", aux -> item.chave);
            printf("nome: %s\n", aux -> item.nome);
            printf("idade: %d\n", aux  -> item.idade);
            printf("\n");
            aux = aux -> Ant;
        }
    }
    printf("\n");
}

void Status(TipoLista *lista){
    if(lista -> Primeiro == lista -> Ultimo){
        printf("Lista Primeiro Prox: NULL\n");
        printf("Lista Ultimo: NULL\n");
    }
    else{
        printf("Lista Primeiro Prox: %d\n", lista->Primeiro->Prox->item.chave);
        printf("Lista Ultimo: %d\n", lista->Ultimo->item.chave);
    }
}
