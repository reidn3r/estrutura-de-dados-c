#include "lista.h"
#include <stdio.h>
#include <stdlib.h>


int main(){
    TipoItem p;
    TipoLista lista;
    Celula *item;
    int codigo;
    FLVazia(&lista);

    int opc;

    do{
        printf("(1) Inserir\n");
        printf("(2) Vazia?\n");
        printf("(3) Retirar\n");
        printf("(4) Imprimir\n");
        
        printf("opc: ");
        scanf("%i", &opc);
        if(opc == 1){
            printf("codigo: ");
            scanf("%i", &p.chave);
            
            printf("nome: ");
            scanf("%s", p.nome);

            printf("idade: ");
            scanf("%i", &p.idade);
            
            //Insere(p, &lista);
            InsereOrdenado(p, &lista);
            //InserePrimeiro(p, &lista);
        }

        else if(opc == 2){
            int resp;
            resp = Vazia(lista); //?
            printf("%d\n", resp);
        }

        else if(opc == 3){
            /*
            printf("codigo: ");
            scanf("%d", &codigo);
            
            item = Localiza(codigo, &lista);
            Retira(item, &lista);
            */
           //RetiraUltimo(&lista);
           RetiraPrimeiro(&lista);
        }

        else if(opc == 4){
            Imprime(lista);
        }

    }
    while(opc > 0);


    
    return 0;
}

