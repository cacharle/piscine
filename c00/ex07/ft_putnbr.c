/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 10:51:16 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/04 14:27:32 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
    unsigned int    u_nb;

    u_nb = nb;
    if (nb < 0)
    {
        ft_putchar('-');
        u_nb = -nb;
    }
    if (u_nb > 9)
        ft_putnbr(u_nb / 10);
    ft_putnbr(u_nb % 10);
}
