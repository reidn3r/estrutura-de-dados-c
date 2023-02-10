#ifndef FILA
#define FILA
#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    Celula *Inicio;
    Celula *Fim;
}TipoFila;

void FFVazia(TipoFila *Fila);

void Enfileirar(TipoFila *Fila, TipoItem x);

void Desinfileirar(TipoFila *Fila, TipoItem x);

void PrintFila(TipoFila *Fila);

//Exercício 3
TipoFila InverteFila(TipoFila *Fila);

#endif