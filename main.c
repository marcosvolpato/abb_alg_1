#include <stdio.h>
#include "list.h"
#include "abb.h"
#include "interface.h"
#include <string.h>
//#include "tipos_abb.h"


int main(int argc, char** argv){

	t_arvore *arvore = ar_init();
	char c[5];
	char str[30];
	int page;
	while(strcmp(c, "s")){
		scanf("%s", c);
		if(!strcmp(c, "b") || !strcmp(c, "i"))
			scanf("%s", str);
		if(!strcmp(c, "i"))
			scanf("%d", &page);
		
		if(!strcmp(c, "i"))
			insere(arvore, str, page);
		if(!strcmp(c, "b"))
			buscar(arvore, str);
		if(!strcmp(c, "r"))
			rem(arvore);
	}
	
	return 0;
}