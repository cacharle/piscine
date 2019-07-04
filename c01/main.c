#include <stdio.h>
#include <limits.h>
#include "ex00/ft_ft.c"
#include "ex01/ft_ultimate_ft.c"
#include "ex02/ft_swap.c"
#include "ex03/ft_div_mod.c"
#include "ex04/ft_ultimate_div_mod.c"
#include "ex05/ft_putstr.c"
#include "ex06/ft_strlen.c"
#include "ex07/ft_rev_int_tab.c"
#include "ex08/ft_sort_int_tab.c"

int main()
{
	int i42 = 2;
	int *i = &i42;
	int **a1 = &i;
	int ***a2 = &a1;
	int ****a3 = &a2;
	int *****a4 = &a3;
	int ******a5 = &a4;
	int *******a6 = &a5;
	int ********a7 = &a6;
	int *********a8 = &a7;

	printf("%d before ", i42);
	ft_ft(i);
	printf("%d after\n", i42);

	i42 = 3;
	printf("%d before ", i42);
	ft_ultimate_ft(a8);
	printf("%d after\n", i42);

	int b = 4, c = 6;
	int *bp = &b, *cp = &c;
	printf("before: %d, %d\n", b, c);
	ft_swap(bp, cp);
	printf("after: %d, %d\n", b, c);

	int div, mod;
	ft_div_mod(20, 7, &div, &mod);
	printf("div = %d, mod = %d\n", div, mod);

	int a = 20, f = 3;
	ft_ultimate_div_mod(&a, &f);
	printf("a div = %d, b mod = %d\n", a, f);

	char s[] = "bonjour je suis charles";
	/*int twer =89899999;*/
	/*char s2[3] = {'a', 'b', 'c'};//, '\0'};*/
	/*int qwer = 5445;*/
	ft_putstr(s);
	printf("\n");
	/*ft_putstr(s2);*/
	/*printf("\n");*/

	printf("(23) '%s' length = %d\n", s, ft_strlen(s));

	int t[4] = {1, INT_MAX, INT_MIN, 4};
	ft_rev_int_tab(t, 4);
	for (int i = 0; i < 4; i++)
		printf("%d ", t[i]);
	printf("\n");


	srand(1);
	int t2[50];
	for (int i = 0; i < 50; i++)
		t2[i] = rand();
	ft_sort_int_tab(t2, 50);
	for (int i = 0; i < 50; i++)
		printf("%d ", t2[i]);

	return 0;
}
