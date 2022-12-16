#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

void FLVazia (TipoLista *Lista){
    Lista -> Primeiro = (Celula*) malloc(sizeof(Celula));
    Lista -> Ultimo = Lista -> Primeiro;
    Lista -> Primeiro -> Prox = NULL;
}

int Vazia (TipoLista Lista){
    return (Lista.Primeiro == Lista.Ultimo);
}

void Insere (TipoItem x, TipoLista *Lista)
{
    Lista -> Ultimo -> Prox = (Celula*) malloc(sizeof(Celula));
    Lista -> Ultimo = Lista -> Ultimo -> Prox;
    Lista -> Ultimo -> Item = x;
    Lista -> Ultimo -> Prox = NULL;
}


Celula* Localiza (int cod, TipoLista *Lista)
{
    Celula* paux;
    paux = Lista->Primeiro;
    while ((paux->Prox != NULL) && (paux->Prox->Item.chave != cod))
    {
    paux = paux->Prox;
    }
return (paux);
}

void Retira (Celula* p, TipoLista *Lista){
    Celula* q;
    if (Vazia(*Lista)||p->Prox==NULL){
        printf ("Erro: lista vazia ou posicao inexistente.\n");
    }
    else{
        q = p->Prox;
        p->Prox = q->Prox;
        if (p->Prox == NULL)
        Lista->Ultimo = p;
        free(q);
    }
}


void Imprime (TipoLista Lista){
    Celula* Aux;
    int i=1;
    Aux = Lista.Primeiro -> Prox;
    while (Aux != NULL){
        printf ("\n\nCodigo do elemento %d: %d", i, Aux->Item.chave);
        printf ("\nNome do elemento %d: %s", i, Aux->Item.nome);
        printf ("\nIdade do elemento %d: %d\n\n", i, Aux->Item.idade);
        Aux=Aux->Prox;
        i++;
        }
}