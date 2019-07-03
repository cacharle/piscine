/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 10:51:16 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/03 14:29:34 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	dirty_hack(void)
{
	ft_putchar('2');
	ft_putchar('1');
	ft_putchar('4');
	ft_putchar('7');
	ft_putchar('4');
	ft_putchar('8');
	ft_putchar('3');
	ft_putchar('6');
	ft_putchar('4');
	ft_putchar('8');
}

void	ft_putnbr(int nb)
{
	int i;
	int	rev_digits[100];

	if (nb < 0)
	{
		ft_putchar('-');
		if (nb == -2147483648)
		{
			dirty_hack();
			return ;
		}
		nb = -nb;
	}
	i = 0;
	while (nb > 0)
	{
		rev_digits[i] = nb % 10;
		nb = nb / 10;
		i++;
	}
	while (i > 0)
	{
		i--;
		ft_putchar(rev_digits[i] + '0');
	}
}
