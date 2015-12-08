#ifndef TIPOS_ABB_H
#define TIPOS_ABB_H

typedef struct t_item_list{
	int page;
	struct t_item_list *next;
}t_item_list;

typedef struct t_list{
	t_item_list *first;
}t_list;

typedef struct t_galho{
	char *str;
	int FB;
	t_list *list;
	struct t_galho *dir, *esq;
}t_galho;

typedef struct{
	t_galho *raiz;
}t_arvore;


#endif