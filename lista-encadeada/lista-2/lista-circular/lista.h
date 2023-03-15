#ifndef LISTA
#define LISTA

typedef struct{
    char nome [30];
    int idade;
    int chave;
}TipoItem;

typedef struct Celula{
    struct Celula* Prox;
    TipoItem item;
}Celula;

typedef struct{
    Celula *Primeiro;
}TipoLista;

void FLVazia(TipoLista *lista);

int Vazia(TipoLista lista);

void Insere(TipoLista *lista, TipoItem x);

void Print(TipoLista *lista);

void Conta(TipoLista *lista);

TipoLista CopiaLista(TipoLista *lista);

#endif