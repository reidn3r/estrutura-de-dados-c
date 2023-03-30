#include "hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    TipoItem item;
    int i=0, tamanho=13, idx;
    char chr[128];

    //Inicialização da tabela hash
    TipoLista *array;
    array = THash(tamanho);
    

    //Dado de entrada
    fflush(stdin);
    printf("dado: ");
    fgets(chr, 128, stdin);
    int str_tam = strlen(chr);

    //Insere cada caractere na tabela
    for(i; i<str_tam-1; i++){
        item.data = chr[i];
        idx = (int)chr[i] % 13; //posição da tabela onde será add. o caracter
        Insere(item, &array[idx]);
    }

    printf("Impressao da tabela hash\n");
    /*
        1. Se determianda posição da tabela hash conter uma lista
        encadeada vazia, nada acontece. Caso contrário, o conteúdo
        da lista é impresso.

        2. idx: posição da tabela hash que contém a lista impressa.
    */
    ImprimeTHash(array, tamanho);

    return 0;
}