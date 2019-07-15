/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 12:52:42 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/14 17:44:58 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "include.h"

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

int		get_with_view(t_board board, t_view_point view, int view_line,
						int line_index)
{
	if (view == row_left)
		return (board[view_line][line_index]);
	if (view == row_right)
		return (board[view_line][3 - line_index]);
	if (view == col_up)
		return (board[line_index][view_line]);
	if (view == col_down)
		return (board[3 - line_index][view_line]);
	return (-1);
}

int		check_arg(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '1' && str[i] <= '4'))
			return (FALSE);
		i++;
		if (!str[i])
			break ;
		if (str[i] != ' ')
			return (FALSE);
		i++;
	}
	if (i != 31)
		return (FALSE);
	return (TRUE);
}
