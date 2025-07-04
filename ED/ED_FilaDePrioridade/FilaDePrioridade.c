FilaDePrioridade* criarFila(int capacidade_inicial){
    FilaDePrioridade* fila = (FilaDePrioridade*)malloc(sizeof(FilaDePrioridade));
    fila->elementos = (Elemento*)malloc(sizeof(Elemento)*capacidade_inicial);
    fila->capacidade = capacidade_inicial;
    fila->tamanho = 0;
    return fila;
}

void inserirNaFila(FilaDePrioridade* fila, Elemento novoElemento){
    if(fila->tamanho >= fila->capacidade){
        fila->capacidade *= 2;
        fila->elementos = (Elemento*)realloc(fila->elementos, sizeof(Elemento)*fila->capacidade);
    }

    fila->elementos[fila->tamanho++] = novoElemento;
    moverParaCima(fila, fila->tamanho-1);
}

Elemento extrairMaiorPrioridade(FilaDePrioridade* fila){
    if(fila->tamanho == 0){
        fprintf(stderr, "Fila vazia. Não é possível extrair elemento.\n");
        exit(EXIT_FAILURE);
    }

    Elemento elementoMaiorPrioridade = fila->elementos[0];
    fila->elementos[0] = fila->elementos[--fila->tamanho];
    moverParaBaixo(fila, 0);
    return elementoMaiorPrioridade;
}

void moverParaBaixo(FilaDePrioridade* fila, int indice){
    int indiceDoMaior = indice;
    if(fila->tamanho > indice*2 + 1 && fila->elementos[indice].valor < fila->elementos[indice*2 + 1].valor)
        indiceDoMaior = indice*2 + 1;
    if(fila->tamanho > indice*2 + 2 && fila->elementos[indiceDoMaior].valor < fila->elementos[indice*2 + 2].valor)
        indiceDoMaior = indice*2 + 2;
    if(indiceDoMaior != indice){
        trocar(&fila->elementos[indice], &fila->elementos[indiceDoMaior]);
        moverParaBaixo(fila, indiceDoMaior);
    }
}       

void moverParaCima(FilaDePrioridade* fila, int indice){
    if(!indice) return; 

    if(fila->elementos[indice].valor > fila->elementos[(indice - 1) / 2].valor){
        trocar(&fila->elementos[indice], &fila->elementos[(indice - 1)/2]);
        moverParaCima(fila, (indice-1)/2);
    }
}

void trocar(Elemento* a, Elemento* b){
    Elemento troca;
    troca = *a;
    *a = *b;
    *b = troca;
}

void freeFila(FilaDePrioridade* fila){
    free(fila->elementos);
    free(fila);
}