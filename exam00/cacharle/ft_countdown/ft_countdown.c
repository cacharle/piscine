#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		main(void)
{
	char	a;

	a = '9';
	while (a >= '0')
	{
		ft_putchar(a);
		a--;
	}
	ft_putchar('\n');
}

