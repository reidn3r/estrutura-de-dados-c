#ifndef PILHA
#define PILHA

typedef struct{
    int chave;
}TipoItem;

typedef struct Celula{
    struct Celula *Prox;
    TipoItem item;
}Celula;

typedef struct{
    Celula *Topo;
    Celula *Fundo;
    int Tamanho;
}TipoPilha;


void FPVazia(TipoPilha *pilha);

void Empilha(TipoPilha *pilha, TipoItem x);

void Desempilha(TipoPilha *pilha, TipoItem *Item);

void Print(TipoPilha *pilha);

void PrintREV(TipoPilha *pilha);

#endif