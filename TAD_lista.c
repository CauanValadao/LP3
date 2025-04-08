
#include <stdio.h>
#include <stdlib.h>

#define CAPACIDADE 4

/* TAD lista usando vetor.
   elementos = vetor de inteiros [0..CAPACIDADE-1];
   tamanho= armazena a quantidade de elementos existentes na lista.
   
   Funções:
   void inicializarLista(Lista *lista);
   int estaCheia(Lista *lista);
   int adicionaElemento(Lista *lista, int elemento);
   int removeElemento(Lista *lista, int indice);
   void imprimiLista(Lista *lista);
   
*/
typedef struct {
    int elementos[CAPACIDADE];
    int tamanho;
} Lista;

/* Função para inicializar a lista como uma lista vazia;
   Entrada: uma estrutura do tipo Lista;
   Saída: uma Lista vazia;
*/   
void inicializaLista(Lista *lista) {
    lista->tamanho = 0;
}

/* Função para verificar se a lista está cheia.
   Entrada: uma Lista;
   Saída: verdadeiro se a lista estiver cheia e falso caso contrário.
*/
int estaCheia(Lista *lista) {
    return lista->tamanho == CAPACIDADE;
}

/* Função para adicionar um elemento à lista.
   Entrada: uma Lista e um elemento inteiro;
   Saída: 1 se o elemento foi inserido na Lista e 0 caso contrário (lista sem espaço).
*/
int adicionaElementoAux(Lista *lista){
    int elemento;
    printf("Digite qual elemento deseja adicionar: ");
    scanf("%d", &elemento);
    return adicionaElemento(lista, elemento);
}
int adicionaElemento(Lista *lista, int elemento) {
    if (estaCheia(lista)) {
        return 0; // Falha ao adicionar elemento
    }
    lista->elementos[lista->tamanho] = elemento;
    lista->tamanho++;
    return 1; // Sucesso
}

/* Função para remover um elemento da lista (por índice)
   Entrada: uma Lista e o índice do elemento que se deseja remover.
   Saída: 1 se o elemento foi removido com sucesso ou 0 caso contrário.
*/
int removeElementoAux(Lista *lista){
    int elemento;
    printf("Digite qual elemento deseja remover: ");
    scanf("%d", &elemento);
    return removeElemento(lista, Pesquisa(lista, elemento));
}
int removeElemento(Lista *lista, int indice) {
    if (indice < 0 || indice >= lista->tamanho) {
        return 0; // Índice inválido
    }
    for (int i = indice; i < lista->tamanho - 1; i++) {
        lista->elementos[i] = lista->elementos[i + 1];
    }
    lista->tamanho--;
    return 1; // Sucesso
}

/* Função para imprimir os elementos da lista
   Entrada: uma Lista.
   Saída: os elementos da Lista exibidos na tela.
*/
void imprimiLista(Lista *lista) {
    for (int i = 0; i < lista->tamanho; i++) {
        printf("%d ", lista->elementos[i]);
    }
    printf("\n");
}

void pesquisaAux(Lista *lista){
    int elemento;
    printf("Digite qual elemento deseja pesquisar: ");
    scanf("%d", &elemento);

    int indice = pesquisa(lista, elemento);

    return indice;
}

int Pesquisa(Lista *lista, int elemento){
    for(int i = 0; i < lista->tamanho; i++)
        if(lista->elementos[i] == elemento) return i;
    return -1; 
}



void merge(Lista *lista, int inicio, int meio, int fim) {
    int i, j, k;
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++)
        L[i] = lista->elementos[inicio + i];
    for (j = 0; j < n2; j++)
        R[j] = lista->elementos[meio + 1 + j];

    i = 0;
    j = 0;
    k = inicio;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            lista->elementos[k] = L[i];
            i++;
        } else {
            lista->elementos[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        lista->elementos[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        lista->elementos[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void mergeSort(Lista *lista, int inicio, int fim) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;

        mergeSort(lista, inicio, meio);
        mergeSort(lista, meio + 1, fim);

        merge(lista, inicio, meio, fim);
    }
}

int main() {
    Lista minhaLista;
    inicializaLista(&minhaLista);

    int x = 1;

    while(x != 6){
        printf("1 - Inserir item na lista2 - Remover item da lista\n3 - Exibir lista\n4 - Pesquisar item na lista\n5 - Ordenar crescentemente a lista\n6 - Sair");
        scanf("%d", &x);

        switch (x)
        {
        case 1:
            if(!adicionaElementoAux(&minhaLista)) printf("A lista esta cheia\n");
            break;
        case 2:
            if(!removeElementoAux) printf("O elemento nao se encontra na lista\n");
            break;
        case 3:
            imprimiLista(&minhaLista);
            break;
        case 4:
            
            break;
        case 5:
            mergeSort(&minhaLista, 0, minhaLista.tamanho-1);
        default:
            break;
        }
    }


/*
    adicionaElemento(&minhaLista, 5);
    adicionaElemento(&minhaLista, 2);
    if(!adicionaElemento(&minhaLista, 6)) printf("Nao ha espaco para novo item");

    printf("Lista inicial: ");
    imprimiLista(&minhaLista);

    //removeElemento(&minhaLista, 1); // Remove o elemento de índice 1 (20)
    mergeSort(&minhaLista, 0, 2);
    printf("Lista apos remocao: ");
    imprimiLista(&minhaLista);
    */

    return 0;
}
