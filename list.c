#include "list.h"
t_list *list_init(){
	t_list *list = (t_list*)malloc(sizeof(t_list));
	list->first = NULL;
	return list;
}
t_item_list *list_new_item_list(int page){
	t_item_list *item_list = (t_item_list*)malloc(sizeof(t_item_list));
	item_list->page = page;
	item_list->next = NULL;
	return item_list;
}
//Nota: tem que inserir ordenando
int list_insert(t_list *list, int page){
	if(list->first == NULL){
		t_item_list *item_list = list_new_item_list(page);
		list->first = item_list;
		return 1;
	}else{ 
		t_item_list *item_list_ant = NULL;
		t_item_list *item_list = list->first;
		while(item_list != NULL){
			if(item_list->page > page){
				t_item_list *item_list_new = list_new_item_list(page);
				item_list_new->next = item_list;
				if(item_list_ant != NULL)
					item_list_ant->next = item_list_new;
				else
					list->first = item_list_new;
				return 1;
			}else if(item_list->page == page)
				return 0;
			item_list_ant = item_list;
			item_list = item_list->next;
		}
		t_item_list *item_list_new = list_new_item_list(page);
		item_list_ant->next = item_list_new;
		return 1;
	}	
}
t_item_list *list_search(t_list *list, int page){
	if(list->first == NULL)
		return NULL;
	t_item_list *item_list = list->first;
	while(item_list != NULL){
		if(item_list->page == page)
			return item_list;
		item_list = item_list->next;
	}
	return NULL;
}
int list_pop(t_list *list, int page){
	if(list->first == NULL)
		return -1;
	t_item_list *item_list = list->first;
	t_item_list *item_list_ant = NULL;
	while(item_list != NULL){
		if(item_list->page == page){
			if(item_list_ant != NULL){
				item_list_ant->next = item_list->next;
			}
			int aux = item_list->page;
			free(item_list);
			return aux;
		}
		item_list_ant = item_list;
		item_list = item_list->next;
	}
	return -1;
}
void list_show(t_list *list){
	t_item_list *item_list = list->first;
	int started = 0;
	while(item_list != NULL){
		if(started)
			printf(", ");
		else
			started = 1;
		printf("%d",item_list->page);
			
		item_list = item_list->next;
	}
	printf("\n");
}
int list_is_empty(t_list *list){
	if(list->first == NULL)
		return 1;
	else
		return 0;
}
void list_drop(t_list *list){
	t_item_list *item_list = list->first, *aux;
	while(item_list != NULL){
		aux = item_list;
		item_list = item_list->next;
		free(aux);
	}
	free(list);
}


























