#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int valor;
    struct Node *proximo;
}Node;

typedef struct Lista{
    int size;
    struct Node *inicio;
}Lista;

void inicializaLista(Lista *lista){
    lista->inicio = NULL;
    lista->size=0;
}

void addFinal(int x, Lista *lista){
    Node *node = (Node *)malloc(sizeof(Node));
    Node *aux = (Node *)malloc(sizeof(Node));

    node->valor = x;
    node->proximo=NULL;

    if(lista->inicio == NULL){
        lista->inicio = node;
    }
    else{
        aux = lista->inicio;
        while(aux->proximo != NULL){
            aux = aux->proximo;
        }
        aux->proximo=node;
    }
    lista->size++;
}

void addInicio(int x, Lista *lista){
    Node *node = (Node *)malloc(sizeof(Node));
    node->valor = x;
    node->proximo = lista->inicio;
    lista->inicio = node;
    lista->size++;
}

void removeFinal(Lista *lista){
    //Acha o elemento, desaloca memória e o ponteiro do penultimo aponta pra NULL;
        //tratar lista vazia

    Node *aux = (Node *)malloc(sizeof(Node));
    aux = lista->inicio;
    if(lista->inicio == NULL){
        printf("Lista vazia.\n");
    }
    else{
        if(lista->size == 1){
            aux = lista->inicio;
            free(aux);
            lista->inicio = NULL;
            lista->size--;
        }
        else{
            while(aux->proximo->proximo != NULL){
                aux = aux->proximo;
            }
                free(aux->proximo->proximo);
                aux->proximo = NULL;
                lista->size--;
        }
    }
}

void removeInicio(Lista *lista){
    if(lista->inicio == NULL){
        printf("Lista vazia.\n");
    }
    else{
        Node *aux = (Node *)malloc(sizeof(Node));
        aux = lista->inicio;
        lista->inicio = lista->inicio->proximo;
        free(aux);
        lista->size--;
    }
}

void substituiElemento(int i, int x, Lista *lista){
    /*
        Altera para x o valor do nó localizado no
        índice i e retorna true. Caso i seja maior ou
        igual a quantidade de elementos da lista ou
        menor do que zero, o método deverá
        simplesmente retornar false sem fazer nada a
        mais.
    */
    
    Node *aux = (Node *)malloc(sizeof(Node));
    aux = lista->inicio;
    if(lista->inicio == NULL){
        printf("Lista vazia.\n");
    }
    else{
        if(i > lista->size || i < 0){
            printf("false\n");
        }
        else{
            int idx=0;
            while(idx != i){
                aux = aux->proximo;
                idx++;
            }
            aux->valor = x;
        }
    }
}

int obtemElemento(int i, Lista *lista){ //?????????????
    Node *aux = (Node *)malloc(sizeof(Node));
    int result=-1;
    if(lista->inicio == NULL){
        printf("Lista vazia.\n");
    }

    else if(i > lista->size){
        return result;
    }

    else{
        int idx=0;
        aux = lista->inicio;
        while(idx != i){
            aux = aux->proximo;
            idx++;
        if(idx == i){
            return aux->valor;
            }
        }
    }
}

int obterNumeroOcorrencias(int x, Lista *lista){
    Node *aux = (Node *)malloc(sizeof(Node));
    int cont=0;

    aux = lista->inicio;
    if(lista->inicio == NULL){
        printf("Lista vazia.\n");
    }
    else{
        while(aux != NULL){
            if(aux->valor == x){
                cont++;
            }
            aux = aux->proximo;
        }
    }
    return cont;
}

void print(Lista *lista){
    Node *aux = (Node *)malloc(sizeof(Node));
    aux = lista->inicio;
    printf("[ ");
    while(aux != NULL){
        printf("%d ", aux->valor);
        aux = aux->proximo;
    }
    printf("]\n\n");
}

int main(){
    /*
    void addFinal(int valor) **
    void addInicio(int valor) **
    void removeFinal() **
    void removeInicio() **
    bool substituiElemento(int i, int x) **
    int obtemElemento(int i)
    int obterNumeroOcorrencias(int x) **
    void limparLista() 
    */

    Lista l1;
    int opc, x, index;
    inicializaLista(&l1);

    do{
        printf("(0) Imprime lista.\n");
        printf("(1) Add no final.\n");
        printf("(2) Add no inicio\n");
        printf("(3) Remove Final.\n");
        printf("(4) Remove Inicio\n");
        printf("(5) Substituir Elemento\n");
        printf("(6) Obter elemento.\n");
        printf("(7) Obter Numero de Ocorrencias.\n");

        scanf("%d", &opc);

        if(opc==0){
            print(&l1);
        }

        if(opc==1){
            printf("x: ");
            scanf("%d", &x);
            addFinal(x, &l1);
        }
        if(opc==2){
            printf("x: ");
            scanf("%d", &x);
            addInicio(x, &l1);
        }
        if(opc==3){
            removeFinal(&l1);
        }

        if(opc==4){
            removeInicio(&l1);
        }

        if(opc==5){
            printf("index: ");
            scanf("%d", &index);
            printf("x: ");
            scanf("%d", &x);
            substituiElemento(index, x, &l1);
        }

        if(opc == 6){
            printf("index: ");
            scanf("%d", &index);
            printf("result: %d\n", obtemElemento(index, &l1));
        }

        if(opc==7){
            printf("x: ");
            scanf("%d", &x);
            printf("qtde.: %d\n", obterNumeroOcorrencias(x, &l1));
        }
    }
    while(opc >= 0);
   
    return 0;
}