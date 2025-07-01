#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* esquerda;
    struct No* direita;
} No;

void iniciaArvore(No** raiz);
void alocaNo(No** no, int valor);
void adicionaNo(No** raiz, int valor);
void adicionaNoRec(No* raiz, No* no);
void printaArvoreCrescente(No* raiz);
void desalocaArvore(No* raiz);
void printaArvoreDecrescente(No* raiz);

int main(){
    int n;
    int num;
    
    scanf("%d", &n);

    No *arvorePar, *arvoreImpar;
    iniciaArvore(&arvorePar);
    iniciaArvore(&arvoreImpar);

    for(int i = 0; i < n; i++){
        scanf("%d", &num);
        if(num % 2 == 0)
            adicionaNo(&arvorePar, num);
        else    
            adicionaNo(&arvoreImpar, num);
    }

    if(arvorePar)printaArvoreCrescente(arvorePar);
    if(arvoreImpar)printaArvoreDecrescente(arvoreImpar);

    desalocaArvore(arvorePar);
    desalocaArvore(arvoreImpar);

    return 0;
}

void iniciaArvore(No** raiz){
    *raiz = NULL;
}   
void alocaNo(No** no, int valor){
    *no = (No*)malloc(sizeof(No));
    if(!*no)
        return;

    (*no)->direita = NULL;
    (*no)->esquerda = NULL;
    (*no)->valor = valor;
}
void adicionaNo(No** raiz, int valor){
    No* no = NULL;
    alocaNo(&no, valor);
    if(!*raiz){
        *raiz = no;
        return;
    }
    adicionaNoRec(*raiz, no);
}

void adicionaNoRec(No* raiz, No* no){
    if(no->valor < raiz->valor){
        if(raiz->esquerda)
            adicionaNoRec(raiz->esquerda, no);
        else
            raiz->esquerda = no;
    }
    else{
        if(raiz->direita)
            adicionaNoRec(raiz->direita, no);
        else
            raiz->direita = no;
    }
}

void printaArvoreCrescente(No* raiz){
    if(raiz->esquerda)
        printaArvoreCrescente(raiz->esquerda);
    printf("%d\n", raiz->valor);
    if(raiz->direita)
        printaArvoreCrescente(raiz->direita);
}

void printaArvoreDecrescente(No* raiz){
    if(raiz->direita)
        printaArvoreDecrescente(raiz->direita);
    printf("%d\n", raiz->valor);
    if(raiz->esquerda)
        printaArvoreDecrescente(raiz->esquerda);
}

void desalocaArvore(No* raiz){
    if(!raiz) return;

    desalocaArvore(raiz->direita);
    desalocaArvore(raiz->esquerda);

    free(raiz);
}