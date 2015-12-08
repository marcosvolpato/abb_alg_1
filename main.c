#include <stdio.h>
#include "list.h"
#include "abb.h"
#include "interface.h"
//#include "tipos_abb.h"


int main(int argc, char** argv){
	
	//t_list *list = list_init();
	t_arvore *arvore = ar_init();
	char str_1[] = "chuva";
	insere(arvore, str_1, 5);
	insere(arvore, str_1, 2);
	insere(arvore, str_1, 14);
	insere(arvore, str_1, 3);
	ar_print(arvore->raiz);
	printf("\n\n");
	list_show(arvore->raiz->list);
	//list_insert(list, 9);
	//list_insert(list, 14);
	//list_insert(list, 3);
	//list_pop(list, 14);
	//list_insert(list, 4);
	//list_insert(list, 11);
	//list_insert(list, 18);
	//list_show(list);	
	
	return 0;
}