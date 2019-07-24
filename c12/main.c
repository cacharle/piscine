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
#include "ex08/ft_list_reverse.c"
#include "ex09/ft_list_foreach.c"
#include "ex10/ft_list_foreach_if.c"
#include "ex11/ft_list_find.c"
#include "ex12/ft_list_remove_if.c"
#include "ex13/ft_list_merge.c"
#include "ex14/ft_list_sort.c"
#include "ex15/ft_list_reverse_fun.c"
#include "ex16/ft_sorted_list_insert.c"
#include "ex17/ft_sorted_list_merge.c"

void print_list(t_list *list)
{
	while (list)
	{
		printf("%d", *(int*)list->data);
		if (list->next != NULL)
			printf(", ");
		list = list->next;
	}
	printf("\n");
}

void each(void *data);
int forcmp(void *data_ref, void* data);
int	sortcmp(void *data, void *data_ref);
void ft_free(void *data);
void idontdoshit(void *d);

int main()
{
	int a = 1;
	int b = 2;
	int c = 3;
	int d = 4;
	int e = 5;
	int f = 6;
	int g = 7;
	t_list *list = NULL;

	list = ft_create_elem(&a);
	printf("%d", *(int*)list->data);

	printf("\n--------------\n");
	ft_list_push_front(&list, &b);
	ft_list_push_front(&list, &c);
	print_list(list);
	ft_list_push_front(&list, &d);
	print_list(list);

	printf("--------------size\n");
	printf("size %d\n", ft_list_size(list));
	ft_list_push_front(&list, &d);
	ft_list_push_front(&list, &c);
	ft_list_push_front(&list, &d);
	print_list(list);
	printf("size %d\n", ft_list_size(list));

	printf("--------------last\n");
	printf("last %d", *(int*)ft_list_last(list)->data);

	printf("\n--------------pushback\n");
	print_list(list);
	ft_list_push_back(&list, &g);
	print_list(list);
	t_list *empty = NULL;
	ft_list_push_back(&empty, &e);
	print_list(empty);
	ft_list_push_back(&empty, &f);
	print_list(empty);

	printf("--------------strs\n");
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

	ft_list_clear(list_strs, &ft_free);

	printf("\n--------------at\n");
	printf("%d\n", *(int*)(ft_list_at(list, 0)->data));
	printf("%d\n", *(int*)(ft_list_at(list, 7)->data));
	printf("%s\n", (char*)(ft_list_at(list, 8)));
	printf("%s\n", (char*)(ft_list_at(list, 10)));

	printf("--------------reverse\n");
	print_list(list);
	ft_list_reverse(&list);
	print_list(list);
	print_list(empty);
	ft_list_reverse(&empty);
	print_list(empty);

	printf("--------------foreach\n");
	ft_list_foreach(list, &each);

	printf("\n--------------foreachif\n");
	ft_list_foreach_if(list, &each, &d, &forcmp);

	printf("\n--------------\n");
	t_list *found = ft_list_find(list, &d, &forcmp);
	print_list(found);

	printf("\n--------------removeif\n");
	print_list(list);
	ft_list_remove_if(&list, &d, &forcmp, &idontdoshit);
	print_list(list);

	printf("--------------merge\n");
	print_list(list);
	ft_list_merge(&list, empty);
	print_list(list);

	printf("--------------sort\n");
	print_list(list);
	ft_list_sort(&list, &sortcmp);
	print_list(list);

	printf("--------------revfun\n");
	ft_list_push_front(&list, &b);
	ft_list_push_front(&list, &b);
	ft_list_push_front(&list, &b);
	print_list(list);
	ft_list_reverse_fun(list);
	print_list(list);

	printf("--------------sortinsert\n");
	int	low = 0;
	int big = 8;
	print_list(list);
	ft_sorted_list_insert(&list, &c, &sortcmp);
	print_list(list);
	ft_sorted_list_insert(&list, &d, &sortcmp);
	print_list(list);
	ft_sorted_list_insert(&list, &e, &sortcmp);
	print_list(list);
	ft_sorted_list_insert(&list, &big, &sortcmp);
	print_list(list);
	ft_sorted_list_insert(&list, &low, &sortcmp);
	print_list(list);

	printf("--------------sortmerge\n");
	print_list(empty);
	ft_sorted_list_merge(&empty, list, &sortcmp);
	print_list(empty);
}

void each(void *data)
{
	printf("%d ", *(int*)data * 10);
}

int forcmp(void *data_ref, void* data)
{
	if (*(int*)data_ref == *(int*)data)
		return (0);
	return (1);
}

int	sortcmp(void *data, void *data_ref)
{
	if (*(int*)data < *(int*)data_ref)
		return (-1);
	else if (*(int*)data > *(int*)data_ref)
		return (1);
	else
		return (0);
}

void ft_free(void *data)
{
	free((char*)data);
}

void idontdoshit(void *d)
{
	(void)d;
}
