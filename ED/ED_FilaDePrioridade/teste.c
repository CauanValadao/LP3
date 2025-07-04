#include "FilaDePrioridade.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    FilaDePrioridade* fila = criarFila(5);
    if (fila == NULL) {
        printf("Erro ao criar a fila.\n");
        return 1;
    }
    Elemento e1;
    e1.valor = 10;
    Elemento e2;
    e2.valor = 20;
    Elemento e3;
    e3.valor = 15;
    Elemento e4;
    e4.valor = 5;                                                                                       
    Elemento e5;
    e5.valor = 25;
    Elemento e6;
    e6.valor = 30;
    inserirNaFila(fila, e6);
    inserirNaFila(fila, e1);
    inserirNaFila(fila, e2);
    inserirNaFila(fila, e3);
    inserirNaFila(fila, e4);
    inserirNaFila(fila, e5);

    for(int i = 0; i < fila->tamanho; i++){
        printf("Elemento %d: %d\n", i+1, fila->elementos[i].valor);
    }
    printf("\n");
 
    int i = 1;
    while(fila->tamanho > 0){
        printf("Elemento %d: %d\n", i++, extrairMaiorPrioridade(fila).valor);
    }

    freeFila(fila);

    return 0;

}