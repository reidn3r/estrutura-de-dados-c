#include "lista.h"
#include <stdlib.h>
#include <stdio.h>

void FLVazia(TipoLista *Lista){
    Lista->Primeiro = NULL;
}

int Vazia(TipoLista Lista){
    return (Lista.Primeiro == NULL);   
}

int Insere(TipoLista *Lista, TipoItem x){
    Celula *ins = (Celula*)malloc(sizeof(Celula));
    Celula *aux = (Celula*)malloc(sizeof(Celula));

    if(Lista->Primeiro==NULL){
        Lista->Primeiro = ins;
        ins->Prox = ins;
    }
    else{
        aux = Lista->Primeiro;
        while(aux->Prox != Lista->Primeiro){
            aux = aux->Prox;
        }
        ins->Prox = Lista->Primeiro;
        aux->Prox = ins;
    }
    ins->item = x;
};

void Conta(TipoLista *Lista){
    Celula *aux = (Celula*)malloc(sizeof(Celula));
    aux = Lista->Primeiro;
    if(Lista->Primeiro==NULL){
        printf("Lista Vazia.\n");
    }
    else{
        int cont=1;
        while(aux->Prox != Lista->Primeiro){
            cont++;
            aux = aux->Prox;
        }
        printf("Count: %d\n\n", cont);
    }
};

void Imprime(TipoLista *Lista){
    Celula *aux  = (Celula*)malloc(sizeof(Celula));
    if(Lista->Primeiro==NULL){
        printf("Lista Vazia.\n");
    }
    else{
        aux = Lista->Primeiro;
        printf("chave: %d\n", aux->item.chave);
        printf("nome: %s\n", aux->item.nome);
        printf("idade: %d\n\n", aux->item.idade);
        aux = aux->Prox;
        while(aux != Lista->Primeiro){
            printf("chave: %d\n", aux->item.chave);
            printf("nome: %s\n", aux->item.nome);
            printf("idade: %d\n\n", aux->item.idade);
            aux = aux->Prox;

            }
        }
    }
