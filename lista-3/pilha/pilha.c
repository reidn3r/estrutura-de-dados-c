#include <stdlib.h>
#include <stdio.h>
#include "../includes/fila.h"
    //pilha.h incluso no fila.h

void FPVazia(TipoPilha *pilha){
    pilha -> Topo = NULL;
    pilha -> Fundo = pilha -> Topo;
    pilha -> Tamanho = 0;
}

void Empilha(TipoPilha *pilha, TipoItem x){
    Celula *aux = (Celula*)malloc(sizeof(Celula));
    aux -> item = x;
    if(pilha -> Topo == NULL){
        pilha -> Fundo = aux;
    }
    aux -> Prox = pilha -> Topo;
    pilha -> Topo = aux;
    pilha->Tamanho++;
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
        while(pilha -> Topo != NULL){
            printf("chave: %d\n", pilha->Topo-> item.chave);
            Desempilha(pilha, &pilha->Topo->item);
        } 
        printf("\n\n");
    }
}


//Exercício 2
void PrintREV(TipoPilha *pilha){
    if(pilha -> Topo == NULL){
        printf("Pilha vazia.\n");
    }
    else{
        TipoPilha pilha_copy;
        FPVazia(&pilha_copy);

        while(pilha -> Tamanho > 0){
            Empilha(&pilha_copy, pilha->Topo->item);
            Desempilha(pilha, &pilha->Topo->item);
        }
        Print(&pilha_copy);
    } 
}

//Exercício 4
void RemoveChave(TipoPilha *pilha, int c){
    if(pilha -> Topo == NULL){
        printf("pilha vazia.\n");
    }
    else{
        TipoPilha pilha_aux;
        FPVazia(&pilha_aux);

        while(pilha->Topo->item.chave != c && pilha->Topo != NULL){
            Empilha(&pilha_aux, pilha->Topo->item);
            Desempilha(pilha, &pilha->Topo->item);
        }

        /*
            * Tratamento para quando a chave não é encontrada.
                1. Todo conteúdo da pilha auxiliar é devolvido a pilha original
        */

        if(pilha->Tamanho == 0){
            printf("Chave nao encontrada");
            while(pilha_aux.Topo != NULL){
                Empilha(pilha, pilha_aux.Topo->item);
                Desempilha(&pilha_aux, &pilha_aux.Topo->item);
            }
        }
        /*
            * Tratamento para quando a chave é encontrada
                1. Desempilha o item com a chave encontrada
                2. Devolve o conteúdo da pilha auxiliar para a pilha original
        */
        else{
            Desempilha(pilha, &pilha->Topo->item);
            while(pilha_aux.Topo != NULL){
                Empilha(pilha, pilha_aux.Topo->item);
                Desempilha(&pilha_aux, &pilha_aux.Topo->item);
            }
        }
    }
}
