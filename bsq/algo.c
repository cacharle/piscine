/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samzur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 12:32:19 by samzur            #+#    #+#             */
/*   Updated: 2019/07/24 09:38:57 by samzur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int		ft_min(int nb1, int nb2, int nb3)
{
	int minimum;

	minimum = nb1;
	if (minimum > nb2)
		minimum = nb2;
	if (minimum > nb3)
		minimum = nb3;
	return (minimum);
}

t_cell	solve(t_terrain *terrain)
{
	t_cell	result;
	int		x;
	int		y;

	y = -1;
	result.y = 0;
	result.x = 0;
	result.value = 0;
	while (++y < terrain->rows)
	{
		x = -1;
		while (++x < terrain->columns)
		{
			if (terrain->matrix[y][x] > OBSTACLE && x != 0 && y != 0)
				terrain->matrix[y][x] = 1 + ft_min(terrain->matrix[y - 1][x],
					terrain->matrix[y][x - 1], terrain->matrix[y - 1][x - 1]);
			if (terrain->matrix[y][x] > result.value)
			{
				result.value = terrain->matrix[y][x];
				result.y = y;
				result.x = x;
			}
		}
	}
	return (result);
}

void	solve_and_complete(t_terrain *terrain)
{
	t_cell	result;
	int		row;
	int		column;

	result = solve(terrain);
	column = result.x;
	while (column >= (result.x - result.value + 1))
	{
		row = result.y;
		while (row >= (result.y - result.value + 1))
		{
			terrain->matrix[row][column] = FILLED;
			row--;
		}
		column--;
	}
}
