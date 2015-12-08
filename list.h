#ifndef LIST_H
#define LIST_H
#include <stdio.h>
#include <stdlib.h>
#include "tipos_abb.h"
t_list *list_init();
t_item_list *list_new_item_list(int page);
int list_insert(t_list *list,  int page);
t_item_list *list_search(t_list *list, int page);
int list_pop(t_list *list, int page);
void list_show(t_list *list);
int list_is_empty(t_list *list);
void list_drop(t_list *list);
#endif