#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int valor;
} Elemento;

typedef struct{
    Elemento* elementos;
    int capacidade;
    int tamanho;
} FilaDePrioridade;

FilaDePrioridade* criarFila(int capacidade_inicial);

void inserirNaFila(FilaDePrioridade* fila, Elemento novoElemento);

Elemento extrairMaiorPrioridade(FilaDePrioridade* fila);

void moverParaBaixo(FilaDePrioridade* fila, int indice);

void moverParaCima(FilaDePrioridade* fila, int indice);

void trocar(Elemento* a, Elemento* b);

void freeFila(FilaDePrioridade* fila);