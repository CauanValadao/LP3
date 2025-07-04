//Essas diretivas servem para evitar que um header file seja incluído mais de uma vez
//no mesmo projeto
#ifndef LISTAE_H_INCLUDED
#define LISTAE_H_INCLUDED

#include "Item.h"
#include <stdlib.h>


/********************************************************************
 * Este arquivo contém código para manipular uma lista encadeada de itens.
 * Um item é uma estrutura do tipo tpItem definida pelo usuário em um arquivo .h nomeado de Item.h.
 * Uma lista encadeada é um ponteiro para um nó. Um nó possui dois campos:
 * a) um campo do tipo tpItem;
 * b) um ponteiro para o próximo nó;
 *
 * Obs:
 * -> O tipo tpItem deve conter obrigatóriamente um campo nomeado de id do tipo unsigned int.
 *
 */


typedef  struct Celula tpNo;

//-----------------------------------------------------------------------------
/**
 * @param .
 * @return a lista inicializada com o ponteiro apontando para NULL;
 */
tpNo * initLstE();
/**
 * @param lst = uma Lista de itens;
 * @param item= um item a ser inserido em lst
 * @return a lista se o item foi inserido em lst ou NULL caso contrário.
 */
tpNo*insertLstE(tpNo *lst, tpItem item);
//-----------------------------------------------------------------------------
/**
 * @param lst = uma Lista de itens;
 * @return retorna o item da primeira posição de lst ou NULL caso contrário.
 */
tpItem  getE(tpNo *lst);
//-----------------------------------------------------------------------------
/**
 * Exibe no monitor os itens da lista.
 * @param lst = uma Lista de itens;
 * @return
 */
void printLstE(tpNo *lst);

//-----------------------------------------------------------------------------
/**
 * Verifica se a lista está vazia.
 * @param lst = uma Lista de itens;
 * @return true se lst vazia ou false caso contrário.
 */
booleano isEmptyLstE(tpNo *lst);

//-----------------------------------------------------------------------------
/**
 * Verifica se a lista está vazia.
 * @param lst = uma Lista de itens;
 * @param id = é o identificador que será buscado em lst.
 * @return o item com o id ou NULL se não for encontrado.
 */
tpItem *searchItemLstE(tpNo *lst, unsigned int id);

/** 
 * Remove um elemento da lista. 
 * @param mat = numero de matricula do elemento que deve ser retirado. 
 * @param lst = uma lista de itens.
 */
booleano removeItemLstE(unsigned int mat, tpNo **lst);


/** 
 * Ordena uma lista em ordem crescente. 
 * @param lst = uma lista de itens.
 */
void ordenarLstE(tpNo *lst);


/** 
 * troca os nomes e as matriculas de 2 nos
 * @param no1 = no que sera trocado
 * @param no2 = outro no que sera trocado
 */
void troca(tpNo *no1, tpNo *no2);


#include "ListaE.c"

#endif // LISTAE_H_INCLUDED