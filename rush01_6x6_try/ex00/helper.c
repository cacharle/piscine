/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 12:52:42 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/14 10:36:19 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	unsigned int	p_nb;

	p_nb = nb;
	if (nb < 0)
	{
		write(1, "-", 1);
		p_nb = -nb;
	}
	if (p_nb > 9)
		ft_putnbr(p_nb / 10);
	ft_putchar(p_nb % 10 + '0');
}

int		strlen_ignore_space(char *str)
{
	int	counter;

	counter = 0;
	while (*str)
	{
		if (*str != ' ')
			counter++;
		str++;
	}
}
