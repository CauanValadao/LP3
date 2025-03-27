#include <stdio.h>

void trocar(int* a, int* b){
    int tem = *a;
    *a = *b;
    *b = tem;
}

int partir(int* vetor, int low, int high){
    int pivot = vetor[high];
    int i = (low - 1);

    for(int j = low; j < high; j++){
        if(vetor[j] < pivot){
            i++;
            trocar(&vetor[j], &vetor[i]);
        }
    }
    trocar(&vetor[high], &vetor[i+1]);

    return (i+1);
}


void QuickSort(int* vetor,int low,int high){
    if(low < high){
        int pi = partir(vetor, low, high);

        QuickSort(vetor, low , pi-1);
        QuickSort(vetor, pi+1 ,high);

    }
}

int main(){
    int vetor[10] = {5,234,25,6,1,3,5,2,9,3};
    for(int i = 0; i < 10; i++)
        printf("%d-", vetor[i]);
    QuickSort(vetor, 0, 9);
    printf("\n\n\n");
    for(int i = 0; i < 10; i++)
        printf("%d-", vetor[i]);

    return 0;
}