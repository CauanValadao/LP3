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
 
int alturaArvoreAux(No* raiz);

int alturaArvore(No* raiz);

int estaNaArvore(No* raiz, int valor);

#include "Arvore.c"
