#ifndef HASH
#define HASH

typedef struct{
    char data;
}TipoItem;

typedef struct Celula{
    struct Celula *Prox;
    TipoItem Item;
}Celula;

typedef struct TipoLista{
    Celula *Primeiro;
    Celula *Ultimo;
}TipoLista;


void FLVazia(TipoLista *Lista);

int Vazia(TipoLista *lista);

void Insere(TipoItem x, TipoLista *Lista);

void Retira(struct Celula* p, TipoLista *Lista);

void Imprime(TipoLista *Lista);

//Funções Tabela Hash

TipoLista *THash(int size);

void ImprimeTHash(TipoLista *array, int size);

#endif