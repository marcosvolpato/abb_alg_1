#ifndef ABB_H
#define ABB_H

#include <stdio.h>
#include <stdlib.h>
#include "tipos_abb.h"
#include "interface.h"
//inserir dados, listar dados, pesquisar dados, excluir dados
t_arvore *ar_init();
int ar_insert(t_galho **raiz, t_galho *galho, int *cresceu);
/*
 * booleano que busca na arvore binaria por um galho com 
 * esse id = x e atribui ao ponteiro de t_galho do parametro 
 * o galho encontrado na busca.
 */
int ar_search(t_galho **raiz, t_galho **galho, char str[]);
int ar_remove(t_galho **galho, char str[]);
void ar_print(t_galho *galho);
t_galho *ga_init();
int ga_delete_one(t_arvore **arvore, char str[]);
int ar_search_and_print(t_arvore *arvore, t_galho **raiz, char str[]);
void ar_rem_print(t_arvore *arvore, t_galho *galho);

#endif