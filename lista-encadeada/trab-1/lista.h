#ifndef LISTA
#define LISTA

typedef struct{
    int chave;
    char nome [30]; 
    int idade;
}TipoItem;

typedef struct Celula{
    TipoItem Item;
    struct Celula* Prox;
}Celula;


typedef struct{
    Celula* Primeiro;
    Celula* Ultimo;
}TipoLista;


void FLVazia (TipoLista *Lista);

int Vazia (TipoLista Lista);

void Insere (TipoItem x, TipoLista *Lista);

void InserePrimeiro(TipoItem x, TipoLista *Lista);

void InsereOrdenado(TipoItem x, TipoLista *Lista);

struct Celula* Localiza (int cod, TipoLista *Lista);

void Retira (struct Celula* p, TipoLista *Lista);

void RetiraUltimo(TipoLista *Lista);

void RetiraPrimeiro(TipoLista *Lista);

void Imprime (TipoLista Lista);

#endif