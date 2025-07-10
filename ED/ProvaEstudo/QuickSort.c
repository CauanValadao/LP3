void quickSort(int* vet, int inicio, int fim){
    if(fim > inicio){
        int pivo = particiona(vet, inicio, fim);
        quickSort(vet, inicio, pivo - 1);
        quickSort(vet, pivo + 1, fim);
    }
}

int particiona(int* vet, int inicio, int fim){
    int i = inicio -1;
    int pivot = vet[fim];

    for(int j = 0; j < fim; j++){
        if(vet[j] <= pivot){
            i++;
            troca(&vet[j], &pivot);
        }
    }
    troca(&vet[i+1], &vet[fim]);
}

void troca(int* a, int* b){
    int troca = *a;
    *a = *b;
    *b = troca;
}

