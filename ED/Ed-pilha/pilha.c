/*DEVE IR PARA PILHA.H:*/
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int valor;
    No* prox;
    No* ant;
}No;

typedef struct{
    int quant;
    No *primeiro;
    No *ultimo
}Pilha;
/*ATE AQUI*/

void iniciaLista(Pilha* pilha){
    pilha->quant = 0;
    pilha->primeiro = NULL;
    pilha->ultimo = NULL;
}

No* alocaNo(){
    No *no = (No*)malloc(sizeof(No));
    no->prox = NULL;
    no->valor = 0;
}

int estaNaPilha(Pilha *pilha, int valor){
    No *aux = pilha->primeiro;
    while(aux != NULL){
        if(aux->valor == valor) return 1;
        aux = aux->prox;
    }
    return 0;
}

No* buscaNaPilha(Pilha *pilha, int valor){
    No *aux = pilha->primeiro;
    while(aux != NULL){
        if(aux->valor == valor) return aux;
        aux = aux->prox;
    }
    return NULL;
}

int adicionaNaPilhaAux(Pilha* pilha){
    No *no = alocaNo();
    printf("Digite o valor: ");
    scanf("%d", &no->valor);
    if(estaNaPilha(pilha, no->valor))
        return 0;
    
    adicionaNaPilha(pilha, no);
    return 1;
}

void adicionaNaPilha(Pilha *pilha,No *no){
    if (pilha->ultimo == NULL){
        pilha->primeiro = no;
        pilha->ultimo = no;
        return;
    }
    no->ant = pilha->ultimo;
    pilha->ultimo->prox = no;
    pilha->ultimo = no;
}

int removeDaPilha(Pilha *pilha){
    if(pilha->ultimo == NULL)
        return 0;
    No *aux = pilha->ultimo->ant;
    free(pilha->ultimo);
    aux->prox = NULL;
    pilha->ultimo = aux;
    return 1;
}

int ordenaBubbleSort()

