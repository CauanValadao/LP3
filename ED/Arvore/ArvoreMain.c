#include "Arvore.h"

int main(){
    No* raiz;
    iniciaArvore(&raiz);
    adicionaNo(&raiz, 10);
    adicionaNo(&raiz, 5);
    adicionaNo(&raiz, 17);
    adicionaNo(&raiz, 3);
    adicionaNo(&raiz, 9);
    adicionaNo(&raiz, 21);
    adicionaNo(&raiz, 2);
    adicionaNo(&raiz, 1);
    adicionaNo(&raiz, 27);

    printf("%d oi", alturaArvore(raiz));

    desalocaArvore(raiz);

    return 0;
}