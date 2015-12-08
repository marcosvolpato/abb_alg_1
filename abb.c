#include "abb.h"
#include <ctype.h>
#include "fila.h"

/*
========================== Fun��es de strings =============================
*/
void custom_tolower(char str[]){
	int i = 0;
	while(str[i] != '\0' && str[i] != '\n'){
		str[i] = tolower(str[i]);
		i++;
	}
}
int vem_antes(char str_1[], char str_2[]){
	custom_tolower(str_1);
	custom_tolower(str_2);
	int i = 0, v = -1;
	while(str_1[i] != '\0' && str_1[i] != '\n' && str_2[i] != '\0' && str_2[i] != '\n'){
		if(str_1[i] < str_2[i]){
			v = 1;
			return v;
		}else if(str_1[i] > str_2[i]){
			v = 0;
			return v;
		}
		i++;
	}
	if(str_1[i] == '\0' || str_1[i] == '\n'){
		if(str_2[i] == '\0' || str_2[i] == '\n')
			return v;
		else{
			v = 1;
			return v;
		}
	}else{
		v = 0;
		return v;
	}
}

/*
========================== Fun��es da balanceamento =============================
*/
void EE(t_galho **galho){
	t_galho *pai = *galho;
	t_galho *filho = pai->esq;
	pai->esq = filho->dir;
	filho->dir = pai;
	pai->FB = 0;
	filho->FB = 0;
	*galho = filho;
}
void DD(t_galho **galho){
	t_galho *pai = *galho;
	t_galho *filho = pai->dir;
	pai->dir = filho->esq;
	filho->esq = pai;
	pai->FB = 0;
	filho->FB = 0;
	*galho = filho;
}
void ED(t_galho **galho){
	t_galho *pai = *galho;
	t_galho *filho = pai->esq;
	t_galho *neto = filho->dir;
	pai->esq = neto->dir;
	filho->dir = neto->esq;
	neto->esq = filho;
	neto->dir = pai;
	switch(neto->FB){
		case -1:
			pai->FB = 1;
			filho->FB = 0;
			break;
		case 0:
			pai->FB = 0;
			filho->FB = 0;
			break;
		case 1:
			pai->FB = 0;
			filho->FB = 1;
			break;
	}	
	neto->FB = 0;
	*galho = neto;
}
/*
========================== Fun��es da arvore =============================
*/
t_arvore *ar_init(){
	t_arvore *arvore = (t_arvore*)malloc(sizeof(t_arvore));
	arvore->raiz = NULL;
	return arvore;
}

int ar_insert(t_galho **raiz, t_galho *galho, int *cresceu){
	if(*raiz== NULL){
		*raiz = galho;
		*cresceu = 1;
		return 1;
	}
	int v = vem_antes(galho->str, (*raiz)->str);
	if(v == -1)
		return 0;
	else if(v == 1){
		if(ar_insert(&(*raiz)->esq, galho, cresceu)){
			
			return 1;
		}else
			return 0;
	}
	else if(v == 0){
		if(ar_insert(&(*raiz)->dir, galho, cresceu)){
			
			return 1;
		}else
			return 0;
	}
	else
		return 0;
	
}
void ar_print(t_galho *galho){ 
    if (galho == NULL) 
		return;
    printf("\n\n%s\n%d", galho->str, galho->FB); 
    ar_print(galho->esq);
    ar_print(galho->dir);
}

int ar_search(t_galho **raiz, t_galho **galho, char str[]){
	if(*raiz == NULL)
		return 0;
	else if(vem_antes(str, (*raiz)->str) == 1)
		return (ar_search(&(*raiz)->esq, galho, str));
	else if(vem_antes(str, (*raiz)->str) == 0)
		return (ar_search(&(*raiz)->dir, galho, str));
	else{
		*galho = *raiz;
		return 1;
	} 
}
int ar_search_and_print(t_arvore *arvore, t_galho **raiz, char str[]){
	if(*raiz == NULL)
		return 0;
	else if(vem_antes(str, (*raiz)->str) == 1){
		int result = ar_search_and_print(arvore, &(*raiz)->esq, str);
		if(result){
			printf("%s ", str);
			buscar(arvore, str);
		}
		return result;
	}
	else if(vem_antes(str, (*raiz)->str) == 0){
		int result = ar_search_and_print(arvore, &(*raiz)->dir, str);
		if(result){
			printf("%s ", str);
			buscar(arvore, str);
		}
		return result;
	}
	else{
		printf("%s ", str);
		buscar(arvore, str);
		return 1;
	} 
}
void ar_rem_print(t_arvore *arvore, t_galho *galho){ 
    if (galho == NULL) 
		return;
    //printf("\n\n%s\n%d", galho->str, galho->FB); 
    printf("%s ", galho->str);
	buscar(arvore,  galho->str);
    ar_rem_print(arvore, galho->esq);
    ar_rem_print(arvore, galho->dir);
}
t_galho *ga_init(){
	t_galho *galho = (t_galho*)malloc(sizeof(t_galho));
	galho->dir = NULL;
	galho->esq = NULL;
	galho->str = NULL;
	galho->list = NULL;
	galho->FB = 0;
	return galho;
}
void ar_rem_print_nivel(t_arvore *arvore, t_galho *galho){ 
    if (galho == NULL) 
		return;
    //printf("\n\n%s\n%d", galho->str, galho->FB); 
    ///////printf("%s ", galho->str);
    if(galho->esq != NULL){
    	printf("%s ", galho->esq->str);
		buscar(arvore,  galho->esq->str);
	}
    if(galho->dir != NULL){
    	printf("%s ", galho->dir->str);
		buscar(arvore,  galho->dir->str);
	}
    ar_rem_print_nivel(arvore, galho->esq);
    ar_rem_print_nivel(arvore, galho->dir);
}
void ar_rem_print_nivel_2(t_arvore *arvore, t_galho *galho){
	//joga na fila a raiz
	//insere os filhos da raiz na fila
	//imprime a raiz
	//coloca os filhos do primeiro filho na fila
	//imprime primeiro filho
	if (galho == NULL) 
		return;
	t_fila *fila = f_init();
	f_push(fila, galho);
	while(!f_isEmpty(fila)){
		t_f_no *f_no = f_pop(fila);
		if(f_no->galho != NULL){
			printf("%s ", f_no->galho->str);
			buscar(arvore,  f_no->galho->str);
			if(f_no->galho->esq != NULL)
				f_push(fila, f_no->galho->esq);
			if(f_no->galho->dir != NULL)
				f_push(fila, f_no->galho->dir);
		}
	}
	
}








