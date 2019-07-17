#include <stdio.h>
#include <limits.h>
#include <string.h>
#include "ex00/ft_foreach.c"
#include "ex01/ft_map.c"
#include "ex02/ft_any.c"
#include "ex03/ft_count_if.c"
#include "ex04/ft_is_sort.c"
/*#include "ex05/ft_foreach.c"*/
/*#include "ex06/ft_foreach.c"*/
/*#include "ex07/ft_foreach.c"*/

void f_fe(int x);
int	f_ma(int x);
int	f_len(char *x);
int f_cou(char *x);
int f_sor(int x, int y);

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
	printf("sorted %d", ft_is_sort(sorted, 6, &f_sor));

	printf("\n------------------------\n");

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

int f_sor(int x, int y)
{
	if (x == y)
		return (0);
	return x < y ? -1 : 1;
}
