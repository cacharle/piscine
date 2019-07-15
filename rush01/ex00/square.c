/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 12:31:20 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/14 15:04:11 by cacharle         ###   ########.fr       */
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
	i = 0;
	j = 0;
	while (i < 16)
	{
		if (arg[i] == ' ')
		{
			arg++;
			continue;
		}
		views[j][i % 4] = arg[i] - '0';
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

int		**init_square(int size)
{
	int i;
	int j;
	int **square;

	square = malloc(sizeof(int*) * size);
	i = 0;
	while (i < size)
	{
		square[i] = malloc(sizeof(int) * size);
		j = 0;
		while (j < size)
			square[i][j++] = 0;
		i++;
	}
	return (square);
}

/*
** Duplicate the square, create an empty clone
** and copy each element of `square` in it.
*/

int		**dup_square(int **square)
{
	int **clone;
	int	i;
	int	j;

	clone = init_square(4);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			clone[i][j] = square[i][j];
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
		free(square[i++]);
	free(square);
}

/*
** Print each row followed by a line break
** and each element of the row but the last followed by a space.
*/

void	print_square(t_board board)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			ft_putnbr(board[i][j]);
			j++;
			if (j != 4)
				ft_putchar(' ');
		}
		ft_putchar('\n');
		i++;
	}
}
