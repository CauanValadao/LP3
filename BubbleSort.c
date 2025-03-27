#include <stdio.h>

void bubbleSort(int vetor[], int tamanho) {
    int i, j, temp;
    for (i = 0; i < tamanho - 1; i++) {
        for (j = 0; j < tamanho - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}

int main(){
    int vetor[10] = {5,234,25,6,1,3,5,2,9,3};
    for(int i = 0; i < 10; i++)
        printf("%d-", vetor[i]);
    bubbleSort(vetor, 10);
    printf("\n\n\n");
    for(int i = 0; i < 10; i++)
        printf("%d-", vetor[i]);

    return 0;
}