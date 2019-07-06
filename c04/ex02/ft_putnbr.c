/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 07:24:04 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/06 08:47:01 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	int 			i;
	int				rev_digits[100];
	unsigned int	nbu;

	if (nb == 0)
	{
		ft_putchar('0');
		return;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nbu = -nb;
	} else
		nbu = nb;
	i = 0;
	while (nbu > 0)
	{
		rev_digits[i] = nbu % 10;
		nbu /= 10;
		i++;
	}
	while (i > 0)
	{
		i--;
		ft_putchar(rev_digits[i] + '0');
	}
}
