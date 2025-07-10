#include <stdio.h>
#include <stdlib.h>

// ================================================================
// ESTRUTURAS E FUNÇÕES DE AJUDA
// ================================================================

// Struct do Nó (não precisa guardar o fb, ele é calculado na hora)
typedef struct No {
    int valor;
    int altura;
    struct No* esquerda;
    struct No* direita;
} No;

// Struct da Árvore
typedef struct {
    No* raiz;
} Arvore;

// Funções de ajuda para altura e máximo
int getAltura(No* no) {
    if (no == NULL) return -1;
    return no->altura;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

// Aloca um novo nó
No* alocaNo(int valor) {
    No* no = (No*)malloc(sizeof(No));
    no->valor = valor;
    no->esquerda = NULL;
    no->direita = NULL;
    no->altura = 0; // Todo novo nó é uma folha com altura 0
    return no;
}

// ================================================================
// ROTAÇÕES
// ================================================================
No* rotacaoDireita(No* raiz) {
    No* pivo = raiz->esquerda;
    raiz->esquerda = pivo->direita;
    pivo->direita = raiz;
    // Atualiza alturas: primeiro o nó que desceu, depois o que subiu
    raiz->altura = 1 + max(getAltura(raiz->esquerda), getAltura(raiz->direita));
    pivo->altura = 1 + max(getAltura(pivo->esquerda), getAltura(pivo->direita));
    return pivo; // Retorna a nova raiz da sub-árvore
}

No* rotacaoEsquerda(No* raiz) {
    No* pivo = raiz->direita;
    raiz->direita = pivo->esquerda;
    pivo->esquerda = raiz;
    // Atualiza alturas: primeiro o nó que desceu, depois o que subiu
    raiz->altura = 1 + max(getAltura(raiz->esquerda), getAltura(raiz->direita));
    pivo->altura = 1 + max(getAltura(pivo->esquerda), getAltura(pivo->direita));
    return pivo; // Retorna a nova raiz da sub-árvore
}

// ================================================================
// A FUNÇÃO DE INSERÇÃO AVL COMPLETA E DEFINITIVA
// ================================================================
No* inserirAVL(No* no, int valor) {
    if (no == NULL) {
        return alocaNo(valor);
    }

    if (valor < no->valor) {
        no->esquerda = inserirAVL(no->esquerda, valor);
    } else if (valor > no->valor) {
        no->direita = inserirAVL(no->direita, valor);
    } else {
        return no; 
    }

    no->altura = 1 + max(getAltura(no->esquerda), getAltura(no->direita));

    int fb = getAltura(no->direita) - getAltura(no->esquerda);


    if (fb > 1) {
        if (getAltura(no->direita->esquerda) > getAltura(no->direita->direita)) {
            no->direita = rotacaoDireita(no->direita);
            return rotacaoEsquerda(no);
        }
        else {
            return rotacaoEsquerda(no);
        }
    }

    else if (fb < -1) {
        if (getAltura(no->esquerda->direita) > getAltura(no->esquerda->esquerda)) {
            no->esquerda = rotacaoEsquerda(no->esquerda);
            return rotacaoDireita(no);
        }
        else {
            return rotacaoDireita(no);
        }
    }
    return no;
}

// Função "wrapper" que o usuário chama
void inserirNo(Arvore* arvore, int valor) {
    if (arvore != NULL) {
       arvore->raiz = inserirAVL(arvore->raiz, valor);
    }
}

void removerNo(Arvore* arvore, int valor){
    if(arvore != NULL){
        arvore->raiz = removerAVL(arvore->raiz, valor);
    }
}

No* removerAVL(No* no, int valor){
    if(no == NULL) return NULL;

    if(valor < no->valor)
        no->esquerda = removerAVL(no->esquerda, valor);
    else if(valor > no->valor)
        no->direita = removerAVL(no->direita, valor);
    else{
        if(!no->esquerda && !no->direita){
            free(no);
            return NULL;
        }
        if(!no->esquerda){
            No* direita = no->direita;
            free(no);
            return direita;
        }
        if(!no->direita){
            No* esquerda = no->esquerda;
            free(no);
            return esquerda;
        }
        No* substituto = getMinimo(no->direita);
        no->valor = substituto->valor;
        no->direita = removerAVL(no->direita, substituto->valor);
    }
    no->altura = 1 + max(getAltura(no->esquerda), getAltura(no->direita));
    int fb = getAltura(no->direita) - getAltura(no->esquerda);
    
    if(fb < -1){
        if(getAltura(no->esquerda->direita) > getAltura(no->esquerda->esquerda))
            no->esquerda = rotacaoEsquerda(no->esquerda);
        return rotacaoDireita(no);
    }
    if(fb > 1){
        if(getAltura(no->direita->esquerda) > getAltura(no->direita->direita))
            no->direita = rotacaoDireita(no->direita);
        return rotacaoEsquerda(no);
    }

    return no;
}

No* getMinimo(No* no){
    if(!no) return NULL;

    while(no->esquerda){
        no = no->esquerda;
    }

    return no;
}

// Função para imprimir (para teste)
void emOrdem(No* no) {
    if (no != NULL) {
        emOrdem(no->esquerda);
        printf("%d(h:%d) ", no->valor, no->altura);
        emOrdem(no->direita);
    }
}

int altura(No* raiz){
    if(raiz == NULL) return -1;

    int esquerda = altura(raiz->esquerda);

    int direita = altura(raiz->direita);

    if(esquerda > direita) return 1 + esquerda;
    else return 1 + direita;
}

int comparaArvores(No* arvore1, No* arvore2){
    if(!arvore1 && !arvore2) return 1;

    if(!arvore1 || !arvore2) return 0;
    
    if(arvore1->valor != arvore2->valor) return 0;

    return comparaArvores(arvore1->esquerda, arvore2->esquerda) && comparaArvores(arvore1->direita, arvore2->direita);
}


int main() {
    Arvore arvore;
    arvore.raiz = NULL;

    printf("--- Teste rotacao simples a Esquerda ---\n");
    inserirNo(&arvore, 10);
    inserirNo(&arvore, 20);
    printf("Inserindo 30...\n");
    inserirNo(&arvore, 30);
    emOrdem(arvore.raiz);
    printf("\n\n");

    printf("--- Teste rotacao Dupla Direita-Esquerda ---\n");
    arvore.raiz = NULL;
    inserirNo(&arvore, 10);
    inserirNo(&arvore, 30);
    printf("Inserindo 20...\n");
    inserirNo(&arvore, 20);
    emOrdem(arvore.raiz);
    printf("\n\n");
    
    printf("%d", altura(arvore.raiz));
    return 0;
}