#ifndef LISTA
#define LISTA

typedef struct{
    char nome [30];
    int idade;
    int chave;
}TipoItem;

typedef struct Celula{
    struct Celula* Prox;
    struct Celula* Ant;
    TipoItem item;
}Celula;

typedef struct{
    Celula *Primeiro;
}TipoLista;

void FLVazia(TipoLista *lista);

void InsereFinal(TipoLista *lista, TipoItem x);

//Ex. 5
void RemoveInicio(TipoLista *lista);

void Print(TipoLista *lista);

#endif