#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

void inicializaLista(Lista *lista){
    lista->inicio = NULL;
    lista->ultimo = NULL;
    lista->size=0;
}

void addFinal(int x, Lista *lista){
    Node *node = (Node *)malloc(sizeof(Node));
    Node *aux = (Node *)malloc(sizeof(Node));

    node->valor = x;
    node->proximo=NULL;

    if(lista->inicio == NULL){
        lista->inicio = node;
        lista->ultimo = node;
    }
    else{
        aux = lista->inicio;
        while(aux->proximo != NULL){
            aux = aux->proximo;
        }
        aux->proximo=node;
        lista->ultimo = node;
    }
    lista->size++;
}

void addInicio(int x, Lista *lista){
    Node *node = (Node *)malloc(sizeof(Node));

    if(lista->inicio == NULL){
        node->valor = x;
        node->proximo = lista->inicio;

        lista->inicio = node;
        lista->ultimo = node;    
        lista->size++;
    }
    else{
        node->valor = x;
        node->proximo = lista->inicio;
        lista->inicio = node;
        lista->size++;
    }
}

void removeFinal(Lista *lista){
    Node *aux = (Node *)malloc(sizeof(Node));
    aux = lista->inicio;
    if(lista->inicio == NULL){
        printf("Lista vazia.\n");
    }
    else{
        if(lista->size == 1){
            aux = lista->inicio;
            free(aux);
            lista->inicio = NULL;
            lista->ultimo = NULL;
            lista->size--;
        }
        else{
            while(aux->proximo->proximo != NULL){
                aux = aux->proximo;
            }
                free(aux->proximo->proximo);
                aux->proximo = NULL;
                lista->ultimo = aux->proximo;
                lista->size--;
        }
    }
}

void removeInicio(Lista *lista){
    if(lista->inicio == NULL){
        printf("Lista vazia.\n");
    }
    else{
        Node *aux = (Node *)malloc(sizeof(Node));
        aux = lista->inicio;
        lista->inicio = lista->inicio->proximo;
        free(aux);
        lista->size--;
    }
}

void substituiElemento(int i, int x, Lista *lista){    
    Node *aux = (Node *)malloc(sizeof(Node));
    aux = lista->inicio;
    if(lista->inicio == NULL){
        printf("Lista vazia.\n");
    }
    else{
        if(i > lista->size || i < 0){
            printf("false\n");
        }
        else{
            int idx=0;
            while(idx != i){
                aux = aux->proximo;
                idx++;
            }
            aux->valor = x;
        }
    }
}

int obtemElemento(int i, Lista *lista){ //?????????????
    Node *aux = (Node *)malloc(sizeof(Node));
    int result=-1;
    if(lista->inicio == NULL){
        printf("Lista vazia.\n");
    }

    else if(i > lista->size){
        return result;
    }

    else{
        int idx=0;
        aux = lista->inicio;
        while(idx != i){
            aux = aux->proximo;
            idx++;
        if(idx == i){
            return aux->valor;
            }
        }
    }
}

int obterNumeroOcorrencias(int x, Lista *lista){
    Node *aux = (Node *)malloc(sizeof(Node));
    int cont=0;

    aux = lista->inicio;
    if(lista->inicio == NULL){
        printf("Lista vazia.\n");
    }
    else{
        while(aux != NULL){
            if(aux->valor == x){
                cont++;
            }
            aux = aux->proximo;
        }
    }
    return cont;
}

void print(Lista *lista){
    Node *aux = (Node *)malloc(sizeof(Node));
    aux = lista->inicio;
    printf("[ ");
    while(aux != NULL){
        printf("%d ", aux->valor);
        aux = aux->proximo;
    }
    printf("]\n\n");
}

void printLast(Lista *lista){
    Node *aux = (Node *)malloc(sizeof(Node));
    if(lista->inicio == NULL){
        printf("lista vazia.\n");
    }
    else{
        aux = lista->inicio;
        while(aux->proximo != NULL){
            aux = aux->proximo;
        }
        printf("last: %d\n", aux->valor);
    }
}

void limparLista(Lista *lista){
    Node *aux = (Node*)malloc(sizeof(Node));
    Node *aux2 = (Node*)malloc(sizeof(Node));

    if(lista->inicio==NULL){
        printf("Lista vazia.\n");
    }
    else{
        aux = lista->inicio;
        while(aux != NULL){
            aux2 = aux->proximo;
            free(aux);
            aux=aux2;
        }
        lista->inicio = NULL;
        lista->ultimo = NULL;
        lista->size = 0;
    }
    free(aux);
    free(aux2);
}

void removeP(int x, Lista *lista){
    continue;
    /*
    Remove primeira ocorrencia de x
    */
}
