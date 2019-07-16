#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		main(void)
{
	char	ch = 'a';
	while (ch <= 'z')
	{
		if (ch % 2 == 0)
			ft_putchar(ch - 'a' + 'A');
		else
			ft_putchar(ch);
		ch++;
	}
	ft_putchar('\n');
	return 0;
}
