#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

void FLVazia(TipoLista *lista){
    lista -> Primeiro = NULL;
}

int Vazia(TipoLista lista){
    return (lista.Primeiro == NULL);
}

void Insere(TipoLista *lista, TipoItem x){
    Celula *Item = (Celula *)malloc(sizeof(Celula));
    Item -> item = x;

    if(lista->Primeiro == NULL){ //&lista?
        lista -> Primeiro = Item;
        Item -> Prox = Item;
    }
    else{
        Celula *aux = (Celula *)malloc(sizeof(Celula));
        aux = lista -> Primeiro;
        while(aux -> Prox != lista->Primeiro){
            aux = aux -> Prox;
        }
        aux -> Prox = Item;
        Item -> Prox = lista -> Primeiro;
    }
    printf("\n");
}

void Print(TipoLista *lista){
    if(lista->Primeiro == NULL){
        printf("Lista vazia.\n");
    }
    else{
        Celula *aux = (Celula *)malloc(sizeof(Celula));
        aux = lista -> Primeiro;
        printf("chave: %d\n", aux->item.chave);
        printf("nome: %s\n", aux->item.nome);
        printf("idade: %d\n", aux->item.idade);
        printf("\n");

        while(aux -> Prox != lista -> Primeiro){
            aux = aux->Prox;
            printf("chave: %d\n", aux->item.chave);
            printf("nome: %s\n", aux->item.nome);
            printf("idade: %d\n", aux->item.idade);
            printf("\n");
        }
    }
}

//Ex 1.
void Conta(TipoLista *lista){
    if(lista->Primeiro == NULL){
        printf("Lista vazia.\n");
    }
    else{
        Celula *aux = (Celula *)malloc(sizeof(Celula));
        int cont=1;
        aux = lista -> Primeiro;
        while(aux -> Prox != lista -> Primeiro){
            aux = aux->Prox;
            cont++;
        }
        printf("contidadem: %d\n", cont);
    }
}

//Ex 2.
TipoLista CopiaLista(TipoLista *lista){
    if(lista -> Primeiro == NULL){
        printf("Lista vazia.\n");
    }

    else{
        /*
            1. Cria cópia da lista e associa NULL ao Lista->Primeiro
            2. Para cada Célula da lista recebida como parâmetro,
                é alocada uma célula que será associada a lista cópia
            
            Fluxo:
                1. Ponteiro auxiliar recebe a celula inicial da lista a ser copiada
                2. Aloca memória da célula cópia
                3. Copia o conteúdo do auxiliar para a célula cópia (Para a primeira célula copiada,
                    o mesmo já é associado como primeiro da lista cópia)
                4. Aloca memória para a prox. célula a ser copiada 
                5. O próximo da célula cópia aponta para endereço de memória que foi alocado
                6. O auxiliar recebe seu próximo, assim como a célula cópia
                7. O item da atual célula cópia recebe o item de auxiliar.
                8. Repete até percorrer toda a lista 
                9. Retorna o endereço da primeira célula da lista cópia.
        */
        TipoLista lista_copia;
        FLVazia(&lista_copia);

        Celula *aux = (Celula *)malloc(sizeof(Celula));
        aux = lista -> Primeiro;

        Celula *copy = (Celula *)malloc(sizeof(Celula));
        copy->item = aux->item;
        lista_copia.Primeiro = copy;

        if(aux -> Prox == lista -> Primeiro){
            copy->Prox = copy;
        }
        else{
            while(aux->Prox != lista -> Primeiro){
                Celula *Prox = (Celula *)malloc(sizeof(Celula));

                copy->Prox = Prox;
                aux = aux->Prox;

                copy = copy-> Prox;
                copy->item = aux->item;
            }
            copy->Prox = lista_copia.Primeiro;
            return lista_copia;
        }
    }
}
