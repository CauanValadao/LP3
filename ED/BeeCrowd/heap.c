#include <stdlib.h>
#include <stdio.h>

typedef struct{
    int tempo;
    int multa;
    double prioridade;
} Dragao;

typedef struct{
    Dragao* dragoes;
    int capacidade;
    int tamanho;
} MaxHeap;

MaxHeap* create_heap(int capacidade_inicial);

void insert(MaxHeap* heap, Dragao novoDragao);

Dragao extract_max(MaxHeap* heap);

void heapify_down(MaxHeap* heap, int indice);

void heapify_up(MaxHeap* heap, int indice);

void swap(Dragao* a, Dragao* b);

void free_heap(MaxHeap* heap);

int main(){

    int dragaoTemp, dragaoMulta;
    long long multaTotal = 0;
    long long multaDiaria = 0;
    Dragao novoDragao;
    Dragao sendoTreinado;

    MaxHeap* alojamento = create_heap(100005);

    while (scanf("%d %d", &dragaoTemp, &dragaoMulta) == 2){
        novoDragao.multa = dragaoMulta;
        novoDragao.tempo = dragaoTemp;
        novoDragao.prioridade = 1.0*dragaoMulta/dragaoTemp;
        insert(alojamento, novoDragao);
        multaDiaria += novoDragao.multa;

        
        sendoTreinado = extract_max(alojamento);
        multaDiaria -= sendoTreinado.multa;
        

        multaTotal += multaDiaria*sendoTreinado.tempo;

        for(int i = sendoTreinado.tempo-1; i > 0 && scanf("%d %d", &dragaoTemp, &dragaoMulta) == 2; i--){
            novoDragao.multa = dragaoMulta;
            novoDragao.tempo = dragaoTemp;
            novoDragao.prioridade = 1.0*dragaoMulta/dragaoTemp;
            insert(alojamento, novoDragao);
            multaDiaria += novoDragao.multa;
            multaTotal += novoDragao.multa*i;
        }
    }

    while(alojamento->tamanho > 0){
        sendoTreinado = extract_max(alojamento);
        multaDiaria -= sendoTreinado.multa;

        multaTotal += multaDiaria*sendoTreinado.tempo;
    }

    printf("%lld\n", multaTotal);

    return 0;
}

MaxHeap* create_heap(int capacidade_inicial){
    MaxHeap* heap = (MaxHeap*)malloc(sizeof(MaxHeap));
    heap->capacidade = capacidade_inicial;
    heap->tamanho = 0;
    heap->dragoes = (Dragao*)malloc(sizeof(Dragao)*capacidade_inicial);
    return heap;
}

void insert(MaxHeap* heap, Dragao novoDragao){
    if(heap->tamanho == heap->capacidade){
        heap->capacidade *= 2;
        heap->dragoes = (Dragao*)realloc(heap->dragoes, sizeof(Dragao)*heap->capacidade);
    }
    
    heap->dragoes[heap->tamanho++] = novoDragao;
    heapify_up(heap, heap->tamanho - 1);
}

Dragao extract_max(MaxHeap* heap){
    Dragao dragaoMaiorPrioridade = heap->dragoes[0];
    heap->dragoes[0] = heap->dragoes[--heap->tamanho];
    heapify_down(heap, 0);
    return dragaoMaiorPrioridade;
}

void heapify_down(MaxHeap* heap, int indice){
    int maiorIndice = indice;

    if(heap->tamanho-1 >= indice*2 + 1  && heap->dragoes[indice].prioridade < heap->dragoes[indice*2 + 1].prioridade)
        maiorIndice = indice*2 + 1;
    
    if(heap->tamanho-1 >= indice*2 + 2 && heap->dragoes[maiorIndice].prioridade < heap->dragoes[indice*2 + 2].prioridade)
        maiorIndice = indice*2 + 2;
    
    if(maiorIndice != indice){
        swap(&heap->dragoes[indice], &heap->dragoes[maiorIndice]);
        heapify_down(heap, maiorIndice);
    }
}

void heapify_up(MaxHeap* heap, int indice){
    if(!indice) return;

    if(heap->dragoes[(indice-1)/2].prioridade < heap->dragoes[indice].prioridade){
        swap(&heap->dragoes[(indice-1)/2], &heap->dragoes[indice]);
        heapify_up(heap, (indice-1)/2);
    }

}

void swap(Dragao* a, Dragao* b){
    Dragao temp = *a;
    *a = *b;
    *b = temp;
}

void free_heap(MaxHeap* heap){
    free(heap->dragoes);
    free(heap);
}