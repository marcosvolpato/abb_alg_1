#include "interface.h"
void insere(t_arvore *arvore, char str[], int page){
	t_galho **result = (t_galho**)malloc(sizeof(t_galho*));
	if(ar_search(&(arvore)->raiz, result, str)){
		list_insert((*result)->list, page);
		//printf("\n\ninseriu (1) = %s\n", (*result)->str);
	}else{
		//criar galho
		t_list *list = list_init();
		t_galho *galho = ga_init();
		char *str_new = (char*)malloc(sizeof(char)*(strlen(str)+1));
		strcpy(str_new, str);
		galho->str = &(str_new[0]);
		galho->list = list;
		list_insert(galho->list, page);
		int cresceu;
		ar_insert(&(arvore->raiz), galho, &cresceu);
		//printf("\n\ninseriu (2) = %s\n", (*result)->str);
	}
}
void buscar(t_arvore *arvore, char str[]){
	t_galho **result = (t_galho**)malloc(sizeof(t_galho*));
	if(ar_search(&(arvore)->raiz, result, str)){
		list_show((*result)->list);
		//printf("\n\nstr interna = %s\n", (*result)->str);
	}else{
		printf("0");	
		printf("\n");
	}
}
void rem(t_arvore *arvore){
	//isso retorna um bool... se tiver que colocar os que são 0(zero) usar isso
	//ar_search_and_print(arvore, &(arvore)->raiz, str);
	//ar_rem_print(arvore, arvore->raiz);
	ar_rem_print_nivel_2(arvore, arvore->raiz);
	/*
	if(arvore->raiz != NULL){
		printf("%s ", arvore->raiz->str);
		buscar(arvore,  arvore->raiz->str);
		ar_rem_print_nivel(arvore, arvore->raiz);
	}*/
}