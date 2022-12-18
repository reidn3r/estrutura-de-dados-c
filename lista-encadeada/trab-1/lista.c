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

//Ex 1.
void InsereOrdenado(TipoItem x, TipoLista *Lista){
    Celula *item = (Celula *)malloc(sizeof(Celula));
    Celula *ptr = (Celula *)malloc(sizeof(Celula));

    ptr = Lista -> Primeiro;
    item -> Item = x;

    if(Lista -> Primeiro == Lista -> Ultimo){
        Lista -> Primeiro -> Prox = item;
        Lista -> Ultimo = item;
        Lista -> Ultimo -> Prox = NULL;
    }
    else{
        while(ptr -> Prox != NULL){
            if(item -> Item.chave <= ptr -> Prox -> Item.chave ){
                item -> Prox = ptr -> Prox;
                ptr -> Prox = item;
                break;
            }
            ptr = ptr->Prox;
        }
        if(ptr -> Prox == NULL){
            ptr -> Prox = item;
            item -> Prox = NULL;
            Lista -> Ultimo = item;
        }
    }
}

//Ex 2.
void InserePrimeiro(TipoItem x, TipoLista *Lista){
    Celula *item = (Celula *)malloc(sizeof(Celula));
    item -> Item = x;
    //Lista vazia:
    if(Lista -> Primeiro == Lista -> Ultimo){
        Lista -> Primeiro -> Prox = item;
        Lista -> Ultimo = item;
        Lista -> Ultimo -> Prox = NULL;
    }
    else{
        //lista nao vazia
        item -> Prox = Lista -> Primeiro -> Prox;
        Lista -> Primeiro -> Prox = item;
    }
}


Celula* Localiza (int cod, TipoLista *Lista){
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


//Ex 3.
void RetiraUltimo(TipoLista *Lista){
    if(Lista -> Primeiro == Lista -> Ultimo){
        printf("Lista vazia.\n");
    }
    else{
        Celula *aux = (Celula *)malloc(sizeof(Celula));
        aux = Lista -> Primeiro;
        while(aux -> Prox -> Prox != NULL){
            aux = aux -> Prox;
        }
        free(aux -> Prox);
        aux -> Prox = NULL;
        Lista -> Ultimo = aux;
    }
}

//Ex 4.
void RetiraPrimeiro(TipoLista *Lista){
    if(Lista -> Primeiro == Lista -> Ultimo){
        printf("Lista vazia.\n");
    }
    else{
        Celula *aux = (Celula *)malloc(sizeof(Celula));
        aux = Lista -> Primeiro -> Prox;
        Lista -> Primeiro -> Prox = aux -> Prox;
        if(aux -> Prox == NULL){
            Lista->Ultimo = Lista->Primeiro;
        }
        free(aux);
    }
}

void Imprime (TipoLista Lista){
    Celula* Aux;
    int i=1;
    Aux = Lista.Primeiro -> Prox;
    if(Lista.Primeiro == Lista.Ultimo){
        printf("Lista vazia.\n");
    }
    else{
        while (Aux != NULL){
            printf ("\n\nCodigo do elemento %d: %d", i, Aux->Item.chave);
            printf ("\nNome do elemento %d: %s", i, Aux->Item.nome);
            printf ("\nIdade do elemento %d: %d\n\n", i, Aux->Item.idade);
            Aux=Aux->Prox;
            i++;
            }

    }
}