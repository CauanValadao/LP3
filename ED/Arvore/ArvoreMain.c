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

    int vet[10] = {10,5,17,3,9,21,44,2,1,27};

    for(int i = 0; i < 10; i++){
        if(!estaNaArvore(raiz, vet[i])){
            printf("\n%dnao esta na arvore", vet[i]);
        }
    }

    desalocaArvore(raiz);

    return 0;
}