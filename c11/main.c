#include <stdio.h>
#include <limits.h>
#include <string.h>
#include "ex00/ft_foreach.c"
#include "ex01/ft_map.c"
#include "ex02/ft_any.c"
#include "ex03/ft_count_if.c"
#include "ex04/ft_is_sort.c"
#include "ex06/ft_sort_string_tab.c"
#include "ex07/ft_advanced_sort_string_tab.c"

void f_fe(int x);
int	f_ma(int x);
int	f_len(char *x);
int f_cou(char *x);
int f_sor_dsc(int x, int y);
int f_sor(int x, int y);
int f_lensort(char *a, char *b);

int main()
{
	int tab[] = {1, 2, 3, 45, 67, 12, 89};
	ft_foreach(tab, 7, &f_fe);

	printf("\n------------------------\n");
	int *mapped = ft_map(tab, 7, &f_ma);
	for (int i = 0; i < 7; i++)
		printf("%d ", mapped[i]);
	free(mapped);

	printf("\n------------------------\n");
	char **ev = malloc(sizeof(char) * 5);
	ev[0] = malloc(sizeof(char) * 32);
	ev[1] = malloc(sizeof(char) * 32);
	ev[2] = malloc(sizeof(char) * 32);
	strcpy(ev[0], "bonjour");
	strcpy(ev[1], "j");
	strcpy(ev[2], "charles");
	ev[3] = NULL;
	printf("any %d", ft_any(ev, &f_len));

	printf("\n------------------------\n");
	printf("count if %d", ft_count_if(ev, 3, &f_cou));

	printf("\n------------------------\n");
	int sorted[10] = {1, 2, 3, 4, 5, 5, 6};
	printf("sorted asc %d\n", ft_is_sort(sorted, 6, &f_sor));
	int sorted_dsc[10] = {7, 6, 4, 1, 0, -10};
	printf("sorted dsc %d", ft_is_sort(sorted_dsc, 6, &f_sor_dsc));


	printf("\n------------------------\n");
	char **a = malloc(sizeof(char*) * 8);
	a[0] = malloc(sizeof(char) * 32);
	a[1] = malloc(sizeof(char) * 32);
	a[2] = malloc(sizeof(char) * 32);
	a[3] = malloc(sizeof(char) * 32);
	a[4] = malloc(sizeof(char) * 32);
	a[5] = malloc(sizeof(char) * 32);
	a[6] = malloc(sizeof(char) * 32);
	strcpy(a[0], "dQ4ilBI6T$");
	strcpy(a[1], "16Tz2R$");
	strcpy(a[2], "4zQplLtBc$");
	strcpy(a[3], "7$");
	strcpy(a[4], "7hE84k$");
	strcpy(a[5], "841SqkO$");
	strcpy(a[6], "ItM$");
	a[7] = NULL;
	ft_sort_string_tab(a);
	for (int i = 0; i < 7; i++)
		printf("%s\n", a[i]);

	printf("\n------------------------\n");
	char **b = malloc(sizeof(char*) * 5);
	b[0] = malloc(sizeof(char) * 32);
	b[1] = malloc(sizeof(char) * 32);
	b[2] = malloc(sizeof(char) * 32);
	b[3] = malloc(sizeof(char) * 32);
	strcpy(b[0], "bjour");
	strcpy(b[1], "je");
	strcpy(b[2], "suis");
	strcpy(b[3], "carles");
	b[4] = NULL;
	ft_advanced_sort_string_tab(b, &f_lensort);
	for (int i = 0; i < 5; i++)
		printf("%s\n", b[i]);
}

void f_fe(int x)
{
	printf("%d ", x + 2);
}

int	f_ma(int x)
{
	return (x * 2);
}

int	f_len(char *x)
{
	int counter = 0;
	while (x[counter])
		counter++;
	return counter < 2;
}

int f_cou(char *x)
{
	int counter = 0;
	while (x[counter])
		counter++;
	return counter > 2;
}

int f_sor_dsc(int x, int y)
{
	if (x == y)
		return (0);
	return x > y ? -1 : 1;
}

int f_sor(int x, int y)
{
	if (x == y)
		return (0);
	return x < y ? -1 : 1;
}

int f_lensort(char *a, char *b)
{
	int i =  0;
	int j = 0;

	while (a[i])
		i++;
	while (b[j])
		j++;
	return (i - j);
}
