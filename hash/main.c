/*
    1.  Faça uma implementação de tabela hash que faça a resolução de conflito com uso de uma
    lista encadeada. Considere que a função de transformação seja h(k) = k mod 13 para a k-ésima
    letra do alfabeto, considerando o código ASC II para o valor numérico de cada letra.
*/

#include "hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    TipoItem item;
    int i=0, tamanho=13, idx;
    char chr[128];
        //Escolha arbitrária

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
        if((int)chr[i] != 32){ //32: código ascii do caractere vazio (espaço)
            item.data = chr[i];
            idx = (int)chr[i] % 13; //posição da tabela onde será add. o caractere
            Insere(item, &array[idx]);
        }
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