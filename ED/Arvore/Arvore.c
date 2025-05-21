void iniciaArvore(No** raiz){
    *raiz = NULL;
}   
void alocaNo(No** no, int valor){
    *no = (No*)malloc(sizeof(No));
    if(!*no)
        return;

    (*no)->direita = NULL;
    (*no)->esquerda = NULL;
    (*no)->valor = valor;
}
void adicionaNo(No** raiz, int valor){
    No* no = NULL;
    alocaNo(&no, valor);
    if(!*raiz){
        *raiz = no;
        return;
    }
    adicionaNoRec(*raiz, no);
}

void adicionaNoRec(No* raiz, No* no){
    if(no->valor < raiz->valor){
        if(raiz->esquerda)
            adicionaNoRec(raiz->esquerda, no);
        else
            raiz->esquerda = no;
    }
    else{
        if(raiz->direita)
            adicionaNoRec(raiz->direita, no);
        else
            raiz->direita = no;
    }
}

int alturaArvore(No* raiz){
    if(!raiz) return 0;

    int direita = 1, esquerda = 1;
    
    direita += alturaArvore(raiz->direita);
    esquerda += alturaArvore(raiz->esquerda);

    if(direita > esquerda) 
        return direita;
    return esquerda;
}

void desalocaArvore(No* raiz){
    if(!raiz) return;

    desalocaArvore(raiz->direita);
    desalocaArvore(raiz->esquerda);

    free(raiz);
}

int estaNaArvore(No* raiz, int valor){
    if(!raiz) return 0;
    if(raiz->valor == valor) return 1;

    if(valor > raiz->valor)
        return estaNaArvore(raiz->direita, valor);
    else return estaNaArvore(raiz->esquerda, valor);
}