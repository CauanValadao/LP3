#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int val;
}Conteudo;

typedef struct No{
    Conteudo elemento;
    struct No *prox;
}No;

typedef struct{
    No *comeco;
    No *fim;
    int tamanho;
}Lista;

Lista iniciaLista();
  
No* alocaNo(int elemento);
 
void insereElementoFim(Lista *lista, int elemento);

int removeElemento(Lista *lista, int elemento);
   
int tamanhoLista(Lista *lista);

void organizaLista(Lista *lista);

void mergeSort(int* vet,int inicio,int fim);

void merge(int* vet, int inicio, int meio, int fim);



int main(){
    Lista lista = iniciaLista();


    insereElementoFim(&lista, 54);
    insereElementoFim(&lista, 5);
    insereElementoFim(&lista, 2);
    insereElementoFim(&lista, 1);
    

    No *aux = lista.comeco;

    while(aux != NULL){
        printf("%d\n",aux->elemento.val);
        aux = aux->prox;
    }
    printf("\n\n\n");

    organizaLista(&lista);

    aux = lista.comeco;

    while(aux != NULL){
        printf("%d\n",aux->elemento.val);
        aux = aux->prox;
    }


    return 0;
}

Lista iniciaLista(){
    Lista lista;
    lista.comeco = NULL;
    lista.fim = NULL;
    lista.tamanho = 0;
    return lista;
}

No* alocaNo(int elemento){
    No *no = (No*)malloc(sizeof(No));
    no->elemento.val = elemento;
    no->prox = NULL;
    return no;
}

void insereElementoFim(Lista *lista, int elemento){
    No* no = alocaNo(elemento);

    if(lista->comeco == NULL){     //caso seja o primeiro No adicionado na lista
        lista->comeco = no;
        lista->fim = no;
    }

    else{
    lista->fim->prox = no;
    lista->fim = no;
    }

    lista->tamanho++;
}

int removeElemento(Lista *lista, int elemento){
    No *remove;
    No *aux = lista->comeco;

    if(aux->elemento.val == elemento){
        lista->comeco = lista->comeco->prox;
        free(aux);
        lista->tamanho--;
        return 1;
    }
    
    while(aux->prox != NULL){
        if(aux->prox->elemento.val == elemento){
            remove = aux->prox;
            aux->prox = aux->prox->prox;
            free(remove);
            lista->tamanho--;
            return 1;
        }
        aux = aux->prox;
    }
    return 0;
}

int tamanhoLista(Lista *lista){
    return lista->tamanho;
}

void organizaLista(Lista *lista){
    int *vet = (int*)malloc(sizeof(int)*lista->tamanho);
    No *aux = lista->comeco;

    for(int i = 0; i < lista->tamanho; i++){
        vet[i] = aux->elemento.val;
        aux = aux->prox;
    }
    
    mergeSort(vet, 0, lista->tamanho-1);
 
    aux = lista->comeco;
    for(int i = 0; i < lista->tamanho; i++){
        aux->elemento.val = vet[i];
        aux = aux->prox;
    }
    free(vet);
}

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
    
    for(int i = 0; i < tamanho; i++)
        vet[inicio + i] = temp[i];

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