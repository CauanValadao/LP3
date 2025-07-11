#include <stdio.h>
#include <stdlib.h>

void merge(int* vet, int inicio, int meio, int fim){
    int p1 = inicio;
    int p2 = meio + 1;
    int tamanho = fim - inicio + 1;
    int i = 0;

    int* temp = (int*)malloc(sizeof(int)*tamanho);

    while(p1 <= meio && p2 <= fim){
        if(vet[p1] < vet[p2])
            temp[i++] = vet[p1++];
        else
            temp[i++] = vet[p2++];
    }
    while(p1 <= meio)
        temp[i++] = vet[p1++];
    while(p2 <= fim)
        temp[i++] = vet[p2++];

    i = 0;
    
    for(int j = inicio; j <= fim; j++)
        vet[j] = temp[i++];

    free(temp);
}


void mergeSort(int* vet,int inicio,int fim){
    if(inicio < fim){
        int meio = (inicio + fim)/ 2; 

        mergeSort(vet, inicio, meio);
        mergeSort(vet, meio + 1, fim);
        merge(vet, inicio, meio, fim);
    }
}

int main(){
    int vetor[10] = {5,234,25,6,1,3,5,2,9,3};
    for(int i = 0; i < 10; i++)
        printf("%d-", vetor[i]);
    mergeSort(vetor, 0, 9);
    printf("\n\n\n");
    for(int i = 0; i < 10; i++)
        printf("%d-", vetor[i]);

    return 0;
}