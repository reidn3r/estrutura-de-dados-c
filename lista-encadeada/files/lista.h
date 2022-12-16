#ifndef LISTA
#define LISTA

typedef struct Node{
    int valor;
    struct Node *proximo;
}Node;

typedef struct Lista{
    int size;
    struct Node *inicio;
    struct Node *ultimo;
}Lista;

void inicializaLista(Lista *lista);

void addFinal(int x, Lista *lista);

void addInicio(int x, Lista *lista);

void removeFinal(Lista *lista);

void removeInicio(Lista *lista);

void substituiElemento(int i, int x, Lista *lista);

int obtemElemento(int i, Lista *lista);

int obterNumeroOcorrencias(int x, Lista *lista);

void print(Lista *lista);

void printLast(Lista *lista);

void limparLista(Lista *lista);

void removeP(int x, Lista *lista);

#endif