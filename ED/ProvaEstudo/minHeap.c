#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int valor;
} Elemento;

typedef struct{
    Elemento* elementos;
    int tamanho;
    int capacidade;
} MinHeap;

MinHeap* criaHeap(int capacidadeInicial){
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->elementos = (Elemento*)malloc(sizeof(Elemento)*capacidadeInicial);
    heap->tamanho = 0;
    heap->capacidade = capacidadeInicial;
    return heap;
}

void inserirNoHeap(MinHeap* heap, Elemento elemento){
    if(heap->tamanho == heap->capacidade){
        heap->capacidade *= 2;
        heap->elementos = (Elemento*)realloc(heap->elementos, sizeof(Elemento)*heap->capacidade);
    }
    heap->elementos[heap->tamanho++] = elemento;
    heapfyUp(heap, heap->tamanho-1);
}

void heapfyDown(MinHeap* heap, int indice){
    int indiceDoMenor = indice;
    if(indice*2 + 1 < heap->tamanho && heap->elementos[indice*2 + 1].valor < heap->elementos[indice].valor) indiceDoMenor = indice*2 + 1;
    if(indice*2 + 2 < heap->tamanho && heap->elementos[indice*2 + 2].valor < indiceDoMenor) indiceDoMenor = indice*2 + 2;

    if(indice != indiceDoMenor){
        trocar(&heap->elementos[indice], &heap->elementos[indiceDoMenor]);
        heapfyDown(heap, indiceDoMenor);
    }
}

void heapfyUp(MinHeap* heap, int indice){
    if(indice > heap->tamanho) return;

    while(indice > 0 && heap->elementos[indice].valor < heap->elementos[(indice-1)/2].valor){
        trocar(&heap->elementos[indice], &heap->elementos[(indice-1)/2]);
        indice = (indice-1)/2;
    }
    
}

void trocar(Elemento* a, Elemento* b){
    Elemento troca;
    troca = *a;
    *a = *b;
    *b = troca;
}

void troca(int* a, int* b){
    int troca = *a;
    *a = *b;
    *b = troca;
}

void ordenarVetor(int* vet, int tamanho){
    if(tamanho <= 1) return;

    for(int i = tamanho/2-1; i >= 0; i--)
        heapfyMax(vet, tamanho, i);

    for(int i = tamanho-1; i > 0; i--){
        troca(&vet[0], &vet[i]);

        heapfyMax(vet, i, 0);
    }
}

void heapfyMax(int* vet, int tamanho, int indice){
    int indiceMaior = indice;
    int esquerda = indice*2 + 1;
    int direita = indice*2 + 2;

    if(esquerda < tamanho && vet[indice] < vet[esquerda]) indiceMaior = esquerda;
    if(direita < tamanho && vet[indiceMaior] < vet[direita]) indiceMaior = direita;

    if(indiceMaior != indice){
        troca(&vet[indice], &vet[indiceMaior]);
        heapfyMax(vet, tamanho, indiceMaior);
    }
}