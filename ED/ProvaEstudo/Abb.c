#include <stdio.h>
#include <stdlib.h>

typedef struct{
    No* esquerda;
    No* direita;
    int valor;
} No;

typedef struct{
    No* raiz;
    int altura;
} Arvore;

Arvore* criaArvore(){
    Arvore* arvore = (Arvore*)malloc(sizeof(Arvore));
    arvore->altura = 0;
    arvore->raiz = NULL;
    return arvore;
}

No* alocaNo(int valor){
    No* no = (No*)malloc(sizeof(No));
    no->valor = valor;
    no->esquerda = NULL;
    no->direita = NULL;
    return no;
}

void inserirNo(Arvore* arvore, int valor){
    No* no = alocaNo(valor);
    if(arvore->raiz == NULL){
        arvore->raiz = no;
        return;
    }
    inserirNoRec(arvore->raiz, no);
}

void inserirNoRec(No* raiz, No* no){
    if(no->valor < raiz->valor){
        if(raiz->esquerda)
            inserirNoRec(raiz->esquerda, no);
        else
            raiz->esquerda = no;
    }
    else{
        if(raiz->direita)
            inserirNoRec(raiz->direita, no);
        else
            raiz->direita = no;
    }
}

void removerNo(Arvore* arvore, int valor){
    arvore->raiz = removerNoRec(arvore->raiz, valor);
}

No* removerNoRec(No* atual, int valor){
    if(!atual) return NULL;

    if(valor > atual->valor)
        atual = removerNoRec(atual->direita, valor);
    else if(valor < atual->valor)
        atual = removerNoRec(atual->esquerda, valor);
    else{
        if(!atual->esquerda && !atual->direita) return NULL;
        else if(!atual->esquerda) return atual->direita;
        else if(!atual->direita) return atual->esquerda;
        else{
            No* substituto = getMinimo(atual->direita);
            atual->valor = substituto->valor;
            removerNoRec(atual->direita, atual->valor);
        }
    }
    return atual;
}

No* getMinimo(No* atual){
    if(!atual) return NULL;

    while(atual->esquerda)
        atual = atual->esquerda;
    
    return atual;
}

No* transformaEmArvore(int* vet){
    
}