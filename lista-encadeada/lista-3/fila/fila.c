#include "../includes/fila.h"
#include <stdio.h>
#include <stdlib.h>

void FFVazia(TipoFila *Fila){
    Fila -> Inicio = NULL;
    Fila -> Fim = Fila -> Inicio;
}

void Enfileirar(TipoFila *Fila, TipoItem x){
    if(Fila -> Fim == NULL){
        Fila -> Fim = (Celula *)malloc(sizeof(Celula));
    }
    else{
        Fila -> Fim -> Prox = (Celula *)malloc(sizeof(Celula));
        Fila -> Fim = Fila -> Fim -> Prox;
    }
    Fila -> Fim -> item = x;
    Fila -> Fim -> Prox = NULL;

    if(Fila -> Inicio == NULL){
        Fila -> Inicio = Fila -> Fim;
    }
}

void Desinfileirar(TipoFila *Fila, TipoItem x){
    if(Fila -> Fim == NULL){
        printf("Fila vazia.\n");
    }
    else{
        Celula *q = Fila -> Inicio -> Prox;
        free(Fila -> Inicio);
        Fila -> Inicio = q;
    }
    if(Fila -> Inicio == NULL){
        Fila -> Fim = NULL;
    }
}

void PrintFila(TipoFila *Fila){
    if(Fila -> Fim == NULL){
        printf("Fila vazia.\n");
    }
    else{
        while(Fila -> Inicio != NULL){
            printf("chave: %d\n", Fila->Inicio-> item.chave);
            Desinfileirar(Fila, Fila->Inicio->item);
        }
    }
}

//Exercício 3
TipoFila InverteFila(TipoFila *Fila){
    if(Fila -> Fim == NULL){
        printf("Fila vazia.\n");
    }
    else{
        TipoFila fila_inv;
        FFVazia(&fila_inv);

        TipoPilha pilha_aux;
        FPVazia(&pilha_aux);

        while(Fila -> Fim != NULL){
            Empilha(&pilha_aux, Fila->Inicio->item);
            Desinfileirar(Fila, Fila->Inicio->item);
        }

        while(pilha_aux.Topo != NULL){
            Enfileirar(&fila_inv, pilha_aux.Topo->item);
            Desempilha(&pilha_aux, &pilha_aux.Topo->item);
        }
        return fila_inv;
    }
}



