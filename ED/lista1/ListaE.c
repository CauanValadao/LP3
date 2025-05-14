/********************************************************************
 * Este arquivo contém código para manipular uma lista encadeada de itens.
 * Um item é uma estrutura definida pelo usuário da biblioteca ListaE.h.
 * Uma lista encadeada é um ponteiro para um nó. Um nó possui dois campos:
 * a) um campo do tipo tpItem;
 * b) um ponteiro para o próximo nó;
 *
 * Obs:
 * -> O tipo tpItem deve conter obrigatóriamente um campo nomeado de id do tipo unsigned int.
 *
 */
#include "ListaE.h"
//-----------------------------------------------------------------------------
struct Celula {
       tpItem    item;
       struct Celula  *prox;
};

typedef  struct Celula tpNo;
//-----------------------------------------------------------------------------
/**
 * @param .
 * @return a lista inicializada com o ponteiro apontando para NULL;
 */
tpNo * initLstE(){
    tpNo *lst = NULL;
    return lst;
}

/**
 * @param lst = uma Lista de itens;
 * @param item= um item a ser inserido em lst
 * @return a lista se o item foi inserido em lst ou NULL caso contrário.
 */
tpNo *insertLstE(tpNo *lst, tpItem item){
    tpNo *no = (tpNo*)malloc(sizeof(tpNo));
   	if (no !=NULL){
		no->item = item;
		no->prox = lst;
   		lst=no;
   		return lst;
	}
    return NULL;
}
//-----------------------------------------------------------------------------
/**
 * @param lst = uma Lista não vazia de itens;
 * @return retorna o item da primeira posição de lst.
 */
tpItem  getE(tpNo *lst){
       return lst->item;
}


//-----------------------------------------------------------------------------
/**
 * Exibe no monitor os itens da lista.
 * @param lst = uma Lista de itens;
 * @return
 */
void printLstE(tpNo *lst){
    //tpNo *aux = lst;

    while (lst != NULL) {
            printItem(lst->item);
            printf("\n----------------------------------");
            lst = lst->prox;
    }
}

//-----------------------------------------------------------------------------
/**
 * Verifica se a lista está vazia.
 * @param lst = uma Lista de itens;
 * @return true se lst vazia ou false caso contrário.
 */
booleano isEmptyLstE(tpNo *lst){
    if (lst == NULL) return true;
    return false;
}

//-----------------------------------------------------------------------------
/**
 * Verifica se a lista está vazia.
 * @param lst = uma Lista de itens;
 * @param id = é o identificador que será buscado em lst.
 * @return o item na lista com o id ou NULL se não for encontrado.
 */
tpItem * searchItemLstE(tpNo *lst, unsigned int id){
    if  (lst != NULL){
        if (lst->item.id == id){
            return &(lst->item);
        } else {
            return searchItemLstE(lst->prox, id);
        }
    }
    return NULL;
}


/** 
 * Remove um elemento da lista. 
 * @param mat = numero de matricula do elemento que deve ser retirado. 
 * @param lst = uma lista de itens.
 */
booleano removeItemLstE(unsigned int mat, tpNo **lst){
    if(lst == NULL || *lst == NULL){
        return 0;
    }
    tpNo *aux = *lst;
    tpNo *remove = NULL;

    if(aux->item.id == mat){
        remove = aux;
        *lst = aux->prox;
        free(remove);
        return 1;
    }

    while(aux->prox != NULL){
        if(aux->prox->item.id == mat){
            remove = aux->prox;
            aux->prox = aux->prox->prox;
            free(remove);
            return 1;
        }
        aux = aux->prox;
    }
    return 0;
}

/** 
 * Ordena uma lista em ordem crescente. 
 * @param lst = uma lista de itens.
 */
    void ordenarLstE(tpNo *lst){
    tpNo *aux = lst;
    int tam = 0;

    while(aux != NULL){
        tam++;
        aux = aux->prox;
    }

    

    for (int i = 0; i < tam; i++) {
        aux = lst; 
        for (int j = 0; j < tam - i - 1; j++) {
            if (aux->item.id > aux->prox->item.id) {
                troca(aux, aux->prox);
            }
            aux = aux->prox;
        }
    }
   
}


/** 
 * troca os nomes e as matriculas de 2 nos
 * @param no1 = no que sera trocado
 * @param no2 = outro no que sera trocado
 */
void troca(tpNo *no1, tpNo *no2){
    char tempNome[30];
    int temp = no1->item.id;
    
    no1->item.id = no2->item.id;
    no2->item.id = temp;

    strcpy(tempNome, no1->item.nome);
    strcpy(no1->item.nome, no2->item.nome);
    strcpy(no2->item.nome, tempNome);
}
