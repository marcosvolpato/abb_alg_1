#ifndef FILA_H
#define FILA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "abb.h"
#include "tipos_abb.h"

/*
 *========================== Tipo de dados ===========================
 */
//typedef struct t_vertice t_vertice;



/*
 *========================== Operações ===========================
 */

 /*
  * Aloca uma nova fila vazia e retorna seu ponteiro
  */
t_fila *f_init();

/*
 * Booleano que retorna 1 se a fila estiver vazia
 */
int f_isEmpty(t_fila *fila);

/*
 * Esvazia a fila liberando a memoria de cada nó
 */
void f_empty(t_fila *fila);

/*
 * Insere um ponteiro de vertice na fila
 */
void f_push(t_fila *fila, t_galho *galho);

/*
 * Retorna um se um vertice com o id recebido estiver na fila
 */
int f_hasVertice(t_fila *fila, char str[]);

/*
 * Retira o nó da frente da fila e retorna seu ponteiro
 */
t_f_no *f_pop(t_fila *fila);

/*
 * Libera a memoria da fila
 */
void f_deleta(t_fila *fila);

#endif