#include <stdio.h>
#include "ex00/ft_btree.h"
#include "ex00/btree_create_node.c"
#include "ex01/btree_apply_prefix.c"
#include "ex02/btree_apply_infix.c"
#include "ex03/btree_apply_suffix.c"
#include "ex04/btree_insert_data.c"
#include "ex05/btree_search_item.c"
#include "ex06/btree_level_count.c"

void f_print(void *d);
int	cmp(void *x, void *y);
int	equal(void *x, void *y);

int main()
{
	int	a = 1;
	int	b = 2;
	int	c = 3;
	int	d = 4;
	int	e = 5;
	int	big = 1000;
	int bigger = 10000;
	t_btree *t = btree_create_node(&a);
	t_btree *l = btree_create_node(&b);
	t_btree *r = btree_create_node(&c);
	t->left = l;
	t->right = r;

	printf("%d %p %p\n", *(int*)t->item, t->left, t->right);
	printf("%d %p %p", *(int*)l->item, l->left, l->right);

	printf("\n-----------------\n");
	btree_apply_prefix(t, &f_print);

	printf("\n-----------------\n");
	btree_apply_infix(t, &f_print);

	printf("\n-----------------\n");
	btree_apply_suffix(t, &f_print);

	printf("\n-----------------\n");
	t_btree *sorted = NULL;
	btree_insert_data(&sorted, &c, &cmp);
	btree_insert_data(&sorted, &a, &cmp);
	btree_insert_data(&sorted, &b, &cmp);
	btree_insert_data(&sorted, &e, &cmp);
	btree_insert_data(&sorted, &d, &cmp);
	btree_insert_data(&sorted, &big, &cmp);
	btree_insert_data(&sorted, &big, &cmp);
	/*btree_insert_data(&sorted, &bigger, &cmp);*/
	btree_apply_prefix(sorted, &f_print);

	printf("\n-----------------\n");
	t_btree *empty = NULL;
	t_btree *one = btree_create_node(&a);
	printf("%p\n", btree_search_item(empty, &a, &equal));
	printf("%p\n", (int*)btree_search_item(empty, &a, &equal));
	printf("%d\n", *(int*)btree_search_item(sorted, &a, &equal));
	printf("%d\n", *(int*)btree_search_item(sorted, &big, &equal));
	/*printf("%d\n", *(int*)btree_search_item(sorted, &bigger, &equal));*/

	printf("\n-----------------\n");
	printf("%d\n", btree_level_count(sorted));
	printf("%d\n", btree_level_count(t));
	printf("%d\n", btree_level_count(empty));
	printf("%d\n", btree_level_count(one));
}

void f_print(void *d)
{
	printf("%d ", *(int*)d);
	fflush(stdout);
}

int	cmp(void *x, void *y)
{
	if (*(int*)x < *(int*)y)
		return -1;
	if (*(int*)x > *(int*)y)
		return 1;
	return 0;
}

int	equal(void *x, void *y)
{
	if (*(int*)x == *(int*)y)
		return 0;
	return 1;
}
