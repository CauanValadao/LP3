/********************************************************************
 * Este arquivo cont�m c�digo para manipular uma lista encadeada de itens.
 * Um item � uma estrutura definida pelo usu�rio da biblioteca ListaE.h.
 * Uma lista encadeada � um ponteiro para um n�. Um n� possui dois campos:
 * a) um campo do tipo tpItem;
 * b) um ponteiro para o pr�ximo n�;
 *
 * Obs:
 * -> O tipo tpItem deve conter obrigat�riamente um campo nomeado de id do tipo unsigned int.
 *
 */
#include "ListaDE.h"

/**
 * Inicia uma LDE vazia.
 * @param .
 * @return a lista inicializada com os ponteiros apontando para NULL e quantItens=0;
 */
tpLDE initLstDE(){
    tpLDE lde;
    lde.ptrPrim = NULL;
    lde.ptrUlt  = NULL;
    lde.quantItens = 0;
    return lde;
}

//-----------------------------------------------------------------------------
/**
 * Insere um item no fim da lista.
 * @param lstDE = uma Lista de itens;
 * @param item= um item a ser inserido em lstDE
 * @return 1 se o item foi inserido em lst ou 0 caso contr�rio.
 */
int insertLstDE(tpLDE *lstDE, tpItem item){
    tpNo *no = (tpNo*)malloc(sizeof(tpNo));
   	if (no !=NULL){
		no->item      = item;
		no->ptrProx   = NULL;
		no->ptrAnt    = (*lstDE).ptrUlt;
   		(*lstDE).ptrUlt = no;
   		(*lstDE).quantItens = (*lstDE).quantItens + 1;
   		if ((*lstDE).ptrPrim == NULL) //Se a lista estava vazia
            (*lstDE).ptrPrim = no;
   		return 1;   //1 = elemento inserido
	}
    return 0; //0 = elemento n�o inserido
}
//-----------------------------------------------------------------------------
/**
 * Retorna o primeiro item da lista.
 * @param lst = uma Lista n�o vazia de itens;
 * @return retorna o item da primeira posi��o de lst.
 */
tpItem getItem(tpLDE lstDE){
       return lstDE.ptrPrim->item;
}


//-----------------------------------------------------------------------------
/**
 * Exibe no monitor os itens da lista.
 * @param lst = uma Lista de itens;
 * @return
 */
void printLstDE(tpLDE lst){
    tpNo *aux = lst.ptrPrim;

    while (aux != NULL) {
            printItem(aux->item);
            printf("\n----------------------------------");
            aux = aux->ptrProx;
    }
}

//-----------------------------------------------------------------------------
/**
 * Verifica se a lista est� vazia.
 * @param lst = uma Lista de itens;
 * @return true se lst vazia ou false caso contr�rio.
 */
booleano isEmptyLstDE(tpLDE lst){
    if (lst.quantItens==0) return true;
    return false;
}

//-----------------------------------------------------------------------------
/**
 * Busca um item na lista.
 * @param lst = uma Lista de itens;
 * @param id = � o identificador que ser� buscado em lst.
 * @return o item na lista com o id ou NULL se n�o for encontrado.
 */
tpItem  *searchItemLstDE(tpLDE lst, unsigned int id){
    tpNo *aux = lst.ptrPrim;
    while (aux != NULL){
        if ( (*aux).item.id == id){
            return &(*aux).item;
        } else {
            aux = aux->ptrProx;
        }
    }
    return NULL;
}

tpItem searchItemLstDE2(tpLDE lst, unsigned int id){
    tpNo *aux = lst.ptrPrim;
    while (aux != NULL){
        if ( aux->item.id == id){
            return aux->item;
        } else {
            aux = aux->ptrProx;
        }
    }
    tpItem item;
    item.id = 0;
    return item;
}

int insertLstDE_SR(tpLDE *lstDE, tpItem item){
    if(!searchItemLstDE(*lstDE, item.id)){
        insertLstDE(lstDE, item);
        return 1;
    }
    return 0;    
}

tpNo* buscaPont(tpLDE lst, int id){
    tpNo *aux = lst.ptrPrim;
    while (aux != NULL){
        if ( aux->item.id == id){
            return aux;
        } else {
            aux = aux->ptrProx;
        }
    }
    return NULL;
}

int deleteLstDE(tpLDE *lstDE, unsigned int id){
    tpNo* deletar = buscaPont(*lstDE,id);
    if(!deletar) return 0;
    if(deletar->ptrAnt)
        deletar->ptrAnt->ptrProx = deletar->ptrProx;
    if(deletar->ptrProx)
        deletar->ptrProx->ptrAnt = deletar->ptrAnt;
    
    free(deletar);     
    return 1;                     
}
