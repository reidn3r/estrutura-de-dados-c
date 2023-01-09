#ifndef LISTA
#define LISTA

typedef struct{
    int chave;
    char nome[30];
    int idade;
}TipoItem;

typedef struct Celula{
    Celula *Prox;
    Celula *Ant;
    TipoItem Item;
}Celula;

typedef struct{
    Celula *Primeiro;
    Celula *Ultimo;
}Lista;

void FLVazia(TipoLista *Lista){
    Lista -> Primeiro = (Celula*)malloc(sizeof(Celula));
    Lista -> Ultimo = Lista -> Primeiro;
    Lista -> Primeiro -> Prox = NULL;
    Lista -> Primeiro -> Ant = NULL;
}

void Vazia(TipoLista Lista){
    return(Lista.Primeiro == Lista.Ultimo);
}

void Insere(TipoLista *Lista, TipoItem x){
    Lista -> Ultimo -> Prox = (Celula*)malloc(sizeof(Celula));
    Lista -> Ultimo -> Prox -> Item = x;

    Lista -> Ultimo -> Prox -> Ant = Lista -> Ultimo; 
    Lista -> Ultimo = Lista -> Ultimo -> Prox;
    Lista -> Ultimo -> Prox = NULL;
}

void Imprime(TipoLista *Lista); //Implementar