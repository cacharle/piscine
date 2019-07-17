#include <stdio.h>
#include <string.h>
#include "ex00/ft_list.h"
#include "ex00/ft_create_elem.c"
#include "ex01/ft_list_push_front.c"
#include "ex02/ft_list_size.c"
#include "ex03/ft_list_last.c"
#include "ex04/ft_list_push_back.c"
#include "ex05/ft_list_push_strs.c"
#include "ex06/ft_list_clear.c"
#include "ex07/ft_list_at.c"
/*#include "ex08/ft_list_reverse.c"*/
/*#include "ex09/ft_list_foreach.c"*/
/*#include "ex10/ft_list_foreach_if.c"*/
/*#include "ex11/ft_list_find.c"*/
/*#include "ex12/ft_list_remove_if.c"*/
/*#include "ex13/ft_list_merge.c"*/
/*#include "ex14/ft_list_sort.c"*/
/*#include "ex15/ft_list_reverse_fun.c"*/
/*#include "ex16/ft_sorted_list_insert.c"*/
/*#include "ft_sorted_list_merge.c"*/

void ft_free(void *data);

int main()
{
	t_list *list = NULL;
	int a = 4;
	void *data = &a;

	list = ft_create_elem(data);
	printf("%d\n", *(int*)list->data);

	char b = 'g';
	data = &b;
	ft_list_push_front(&list, data);
	printf("%c\n", *(char*)list->data);
	printf("%d\n", *(char*)list->next->data);
	printf("%s\n", (char*)list->next->next);

	printf("size %d\n", ft_list_size(list));
	ft_list_push_front(&list, data);
	printf("size %d\n", ft_list_size(list));

	printf("last %d\n", *(int*)ft_list_last(list)->data);

	double c = 3.14;
	data = &c;
	ft_list_push_back(&list, data);
	printf("list last %f\n", *(double*)ft_list_last(list)->data);
	t_list *empty = NULL;
	ft_list_push_back(&empty, data);
	printf("empty last %f\n", *(double*)ft_list_last(list)->data);

	char **strs = malloc(sizeof(char*) * 4);
	strs[0] = malloc(sizeof(char) * 32);
	strs[1] = malloc(sizeof(char) * 32);
	strs[2] = malloc(sizeof(char) * 32);
	strs[3] = malloc(sizeof(char) * 32);
	strcpy(strs[0], "bonjour");
	strcpy(strs[1], "je");
	strcpy(strs[2], "suis");
	strcpy(strs[3], "charles");
	t_list *list_strs = ft_list_push_strs(4, strs);
	for (; list_strs; list_strs = list_strs->next)
		printf("%s | ", (char*)list_strs->data);

	/*ft_list_clear(list_strs, &ft_free);*/

	printf("\n--------------\n");
	printf("%d\n", *(int*)(ft_list_at(list, 0)->data));
	printf("%f\n", *(double*)(ft_list_at(list, 1)->data));
	printf("%s\n", (char*)ft_list_at(list, 2));



}

void ft_free(void *data)
{
	free((char*)data);
}
