#ifndef INTERFACE_H
#define INTERFACE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipos_abb.h"
#include "list.h"
#include "abb.h"
void insere(t_arvore *arvore, char str[], int page);
void buscar(t_arvore *arvore, char str[]);
void rem(t_arvore *arvore);

#endif