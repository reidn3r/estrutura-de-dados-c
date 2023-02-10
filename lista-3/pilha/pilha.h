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

//Exercício 2???
void PrintREV(TipoPilha *pilha);

//Exercício 4
void RemoveChave(TipoPilha *pilha, int key);


void Print(TipoPilha *pilha);

#endif