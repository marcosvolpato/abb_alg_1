#include "interface.h"
void insere(t_arvore *arvore, char str[], int page){
	t_galho **result = (t_galho**)malloc(sizeof(t_galho*));
	if(ar_search(&(arvore)->raiz, result, str)){
		list_insert((*result)->list, page);
	}else{
		//criar galho
		t_list *list = list_init();
		t_galho *galho = ga_init();
		galho->str = &(str[0]);
		galho->list = list;
		list_insert(galho->list, page);
		int cresceu;
		ar_insert(&(arvore->raiz), galho, &cresceu);
	}
}