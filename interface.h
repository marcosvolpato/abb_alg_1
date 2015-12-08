#ifndef INTERFACE_H
#define INTERFACE_H
#include <stdio.h>
#include <stdlib.h>
#include "tipos_abb.h"
#include "list.h"
#include "abb.h"
void insere(t_arvore *arvore, char str[], int page);
void buscar(char str[]);
void rem();
void sair();

#endif