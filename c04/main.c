#include <stdio.h>
#include <string.h>
#include "ex00/ft_strlen.c"
#include "ex01/ft_putstr.c"
#include "ex02/ft_putnbr.c"
#include "ex03/ft_atoi.c"
#include "ex04/ft_putnbr_base.c"
#include "ex05/ft_atoi_base.c"

int main()
{
	char *s1 = "jesuis7";
	printf("%d\n", ft_strlen(s1));

	char *s = "bonjour";
	ft_putstr(s);
	printf("\n");


}
