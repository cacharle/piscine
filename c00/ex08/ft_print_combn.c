/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 14:33:09 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/03 15:39:02 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ft_putchar(char c)
{
    write(STDOUT_FILENO, &c, 1);
}

void    comb(int start, int n)
{
    int i;

    if (n == 0)
    {
        ft_putchar(',');
        ft_putchar(' ');
        return ;
    }
    i = start + 1;
    while (i < 10)
    {
        ft_putchar(start + '0');
        ft_putchar(i + '0');
        comb(i, n - 1);
        i++;
    }
}

void	ft_print_combn(int n)
{
    comb(0, n);
}
