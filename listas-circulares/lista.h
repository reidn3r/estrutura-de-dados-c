#ifndef LISTA
#define LISTA

typedef struct{
    int chave;
    char nome[30];
    int idade;
}TipoItem;

typedef struct Celula{
    TipoItem item;
    struct Celula* Prox;
}Celula;

typedef struct{
    Celula* Primeiro;
}TipoLista;


//Funções ---
void FLVazia(TipoLista *Lista);

int Vazia(TipoLista Lista);

int Insere(TipoLista *Lista, TipoItem x);

void Conta(TipoLista *Lista);

void Imprime(TipoLista *Lista);


#endif