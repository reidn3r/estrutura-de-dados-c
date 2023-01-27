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
    Celula *Ultimo;
}TipoLista;

void FLVazia(TipoLista *lista);

void Insere(TipoLista *lista, TipoItem x);

//Ex. 3
void InsereInicio(TipoLista *lista, TipoItem x);

//Ex. 4
void RemoveFinal(TipoLista *lista);

void Print(TipoLista *lista);

void PrintREV(TipoLista *lista);

void Status(TipoLista *lista);

#endif