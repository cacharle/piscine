/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 12:31:20 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/14 13:26:55 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "include.h"

/*
** Parse the program's first argument where each row is in order
** col up, col down, row left, row right
*/

t_views	parse_arg(char *arg)
{
	int		i;
	int		j;
	t_views views;

	views = init_square(4);
	views.size = 4;
	i = 0;
	j = 0;
	while (i < 16)
	{
		if (arg[i] == ' ')
		{
			arg++;
			continue;
		}
		views.self[j][i % 4] = arg[i] - '0';
		if (i % 4 == 3)
			j++;
		i++;
	}
	return (views);
}

/*
** Allocate memory for a 2D array(square) of `size`
** initialize each cell to 0.
*/

t_square	init_square(int size)
{
	int i;
	int j;
	t_square square;

	square.self = malloc(sizeof(int*) * size);
	square.size = size
	i = 0;
	while (i < size)
	{
		square.self[i] = malloc(sizeof(int) * size);
		j = 0;
		while (j < size)
			square.self[i][j++] = 0;
		i++;
	}
	return (square);
}

/*
** Duplicate the square, create an empty clone
** and copy each element of `square` in it.
*/

t_square	dup_square(t_square square)
{
	t_square	clone;
	int			i;
	int			j;

	clone = init_square(4);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			clone.self[i][j] = square.self[i][j];
			j++;
		}
		i++;
	}
	return (clone);
}

/*
** Free each row of the square and the square itself.
*/

void	destroy_square(int **square)
{
	int i;

	i = 0;
	while (i < 4)
		free(square.self[i++]);
	free(square.self);
}

/*
** Print each row followed by a line break
** and each element of the row but the last followed by a space.
*/

void	print_square(t_square square)
{
	int	i;
	int	j;

	i = 0;
	while (i < square.size)
	{
		j = 0;
		while (j < square.size)
		{
			ft_putnbr(square.self[i][j++]);
			if (j != 4)
				ft_putchar(' ');
		}
		ft_putchar('\n');
		i++;
	}
}
