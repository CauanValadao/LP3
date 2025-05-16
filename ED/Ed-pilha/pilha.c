/*DEVE IR PARA PILHA.H:*/
#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* prox;
    struct No* ant;
} No;

typedef struct {
    int quant;
    No *primeiro;
    No *ultimo;
} Pilha;
/*ATE AQUI*/

void adicionaNaPilha(Pilha *pilha, No *no);
void iniciaLista(Pilha* pilha);
void merge(No** vet, int inicio, int meio, int fim);
void mergeSort(No** vet, int inicio, int fim);
void troca(No** vet, int no1, int no2);
int adicionaNaPilhaAux(Pilha* pilha);
int estaNaPilha(Pilha *pilha, int valor);
No* buscaNaPilha(Pilha *pilha, int valor);
int removeDaPilha(Pilha *pilha);
void ordenar(Pilha *pilha);


void iniciaLista(Pilha* pilha){
    pilha->quant = 0;
    pilha->primeiro = NULL;
    pilha->ultimo = NULL;
}

No* alocaNo(){
    No *no = (No*)malloc(sizeof(No));
    no->prox = NULL;
    no->ant = NULL;
    no->valor = 0;
    return no;
}

int estaNaPilha(Pilha *pilha, int valor){
    No *aux = pilha->primeiro;
    while(aux != NULL){
        if(aux->valor == valor) return 1;
        aux = aux->prox;
    }
    return 0;
}

No* buscaNaPilha(Pilha *pilha, int valor){
    No *aux = pilha->primeiro;
    while(aux != NULL){
        if(aux->valor == valor) return aux;
        aux = aux->prox;
    }
    return NULL;
}

int adicionaNaPilhaAux(Pilha* pilha){
    No *no = alocaNo();
    printf("Digite o valor: ");
    scanf("%d", &no->valor);
    if(estaNaPilha(pilha, no->valor))
        return 0;
    
    adicionaNaPilha(pilha, no);
    pilha->quant++;
    return 1;
}

void adicionaNaPilha(Pilha *pilha, No *no){
    if (pilha->ultimo == NULL){
        pilha->primeiro = no;
        pilha->ultimo = no;
        return;
    }
    no->ant = pilha->ultimo;
    pilha->ultimo->prox = no;
    pilha->ultimo = no;
}

int removeDaPilha(Pilha *pilha){
    if(pilha->ultimo == NULL)
        return 0;
    No *aux = pilha->ultimo->ant;
    free(pilha->ultimo);
    aux->prox = NULL;
    pilha->ultimo = aux;
    pilha->quant--;
    return 1;
}

void ordenar(Pilha *pilha){
    No** vet = (No**)malloc(sizeof(No*)*pilha->quant);
    No* aux = pilha->primeiro;
    for(int i = 0; i < pilha->quant; i++){
        vet[i] = aux;
        aux = aux->prox;
    }
    mergeSort(vet, 0, pilha->quant-1);

    pilha->primeiro = vet[0];
    pilha->ultimo = vet[pilha->quant-1];
    pilha->primeiro->ant = NULL;
    pilha->ultimo->prox = NULL;

    for(int i = 0; i < pilha->quant-1; i++){
        vet[i]->prox = vet[i+1];
        vet[i+1]->ant = vet[i];
    }
}

void mergeSort(No** vet, int inicio, int fim){
    if(inicio < fim){
        int meio = (inicio + fim) / 2;

        mergeSort(vet, inicio, meio);
        mergeSort(vet, meio + 1, fim);
        merge(vet, inicio, meio, fim);
    }
}

void merge(No** vet, int inicio, int meio, int fim){
    int p1 = inicio;
    int p2 = meio + 1;
    int tamanho = fim - inicio + 1;
    int i = 0;
    No** temp = (No**)malloc(sizeof(No*)*tamanho);

    while(p1 <= meio && p2 <= fim){
        if(vet[p1]->valor < vet[p2]->valor){
            temp[i++] = vet[p1++];
        }
        else{
            temp[i++] = vet[p2++];
        }
    }
    while(p1 <= meio){
        temp[i++] = vet[p1++];
    }
    while(p2 <= fim){
        temp[i++] = vet[p2++];
    }

    for(int i = 0; i < tamanho; i++)
        vet[inicio + i] = temp[i];
}

int main(){ 
    Pilha pilha;
    iniciaLista(&pilha);
    adicionaNaPilhaAux(&pilha);
    adicionaNaPilhaAux(&pilha);
   

    No *aux = pilha.primeiro;
    while(aux != NULL){
        printf("%d\n",aux->valor);
        aux = aux->prox;
    }

    printf("\n\n\n");

    ordenar(&pilha);

    aux = pilha.primeiro;
    while(aux != NULL){
        printf("%d\n",aux->valor);
        aux = aux->prox;
    }
    printf("\n\n\n");

    return 0;
}

