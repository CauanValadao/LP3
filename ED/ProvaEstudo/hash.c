#include <stdio.h>
#include <stdlib.h>

// 1. O nó da lista encadeada (para colisões)
typedef struct No {
    int chave;          // A chave agora é um inteiro (ex: matrícula)
    char* valor;        // O valor pode continuar sendo uma string (ex: nome)
    struct No* proximo;
} No;

// 2. A própria Tabela Hash (não muda nada aqui)
typedef struct {
    int tamanho;        // Quantas "gavetas" o armário tem
    No** tabela;        // O vetor de ponteiros para os Nós
} TabelaHash;

TabelaHash* criar_tabela(int tamanho){
    TabelaHash* tabelaHash = (TabelaHash*)malloc(sizeof(TabelaHash));
    tabelaHash->tamanho = tamanho;
    tabelaHash->tabela = (No**)malloc(sizeof(No*)*tamanho);
    for(int i = 0; i < tamanho; i++)
        tabelaHash->tabela[i] = NULL;
    return tabelaHash;
}

void inserir(TabelaHash* th, int chave, char* valor){
    int indice = chave % th->tamanho;
    No* no = (No*)malloc(sizeof(No));
    no->chave = chave;
    no->valor = valor;

    no->proximo = th->tabela[indice];
    th->tabela[indice] = no;
}

char* buscar(TabelaHash* th, int chave){
    int indice = chave % th->tamanho;

    No* percorrer = th->tabela[indice]; 

    while(percorrer){
        if(chave == percorrer->chave) return percorrer->valor;
        percorrer = percorrer->proximo;
    }
    
    return NULL;
}


int main() {
    // Criamos uma tabela com 10 posições (índices 0 a 9)
    TabelaHash* th = criar_tabela(10);

    printf("Inserindo elementos...\n");
    // Note que 1, 11 e 31 vão colidir no índice 1.
    // E 5 e 25 vão colidir no índice 5.
    inserir(th, 1, "Ana");
    inserir(th, 5, "Bia");
    inserir(th, 11, "Carlos"); // Colisão com Ana
    inserir(th, 25, "Daniel"); // Colisão com Bia
    inserir(th, 31, "Elisa");  // Colisão com Carlos e Ana

    printf("\nBuscando elementos:\n");

    printf("Busca pela chave 5: %s\n", buscar(th, 5));   // Deve encontrar "Bia"
    printf("Busca pela chave 25: %s\n", buscar(th, 25)); // Deve encontrar "Daniel"
    printf("Busca pela chave 1: %s\n", buscar(th, 1));   // Deve encontrar "Ana"
    printf("Busca pela chave 31: %s\n", buscar(th, 31)); // Deve encontrar "Elisa"
    printf("Busca pela chave 100: %s\n", buscar(th, 100)); // Não deve encontrar (NULL)

    // TODO: Liberar a memória alocada (free) - um bom próximo passo!

    return 0;
}