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
    Celula *ipt = (Celula *)malloc(sizeof(Celula));
    ipt -> item = x;

    if(lista -> Primeiro == lista -> Ultimo){
        lista -> Ultimo = (Celula *)malloc(sizeof(Celula));
        lista -> Ultimo -> item = x;
        lista -> Primeiro -> Prox = lista -> Ultimo;
    }

    else{
        Celula *ipt = (Celula *)malloc(sizeof(Celula));
        ipt -> item = x;
        ipt -> Prox = lista -> Primeiro -> Prox;
        ipt -> Ant = lista -> Primeiro;
        lista -> Primeiro -> Prox = ipt;
    }
    
}

//Ex. 4
void RemoveFinal(TipoLista *lista){
    if(lista -> Primeiro == lista -> Ultimo){
        printf("Lista vazia.\n");
    }
    else{
        Celula *aux = lista -> Ultimo -> Ant;
        free(lista -> Ultimo);
        aux -> Prox = NULL;
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
        Celula *aux = (Celula *)malloc(sizeof(Celula));
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
