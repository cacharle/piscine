/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 14:25:32 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/14 13:30:12 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"
#include <stdio.h>

#define UNASSIGNED 0
#define TRUE 1
#define FALSE 0

/*
** Find all the sudoku 4x4 grid recursively
** print the one that checks out with the given viewpoints
*/

int	solve(t_board board, t_views views)
{
	int		row;
	int		col;
	int		i;
	t_board	board_clone;

	if (!find_next_unassigned(board, &row, &col))
		return (TRUE);
	i = 1;
	while (i <= size)
	{
		board_clone = dup_square(board);
		if (is_alone(board_clone, row, col, i))
		{
			board_clone.self[row][col] = i;
			if (solve(board_clone, views))
			{
				if (check_viewpoints(board_clone, views))
				{
					print_square(board_clone);
					return (TRUE);
				}
				return (FALSE);
			}
		}
		destroy_square(board_clone);
		i++;
	}
	return (FALSE);
}

/*
** Move `row` and `col` to the next unassigned(== 0) position
** returns FALSE if the board is already filled with number, TRUE otherwise
*/

int	find_next_unassigned(t_board board, int *row, int *col)
{
	*row = 0;
	while (*row < board.size)
	{
		*col = 0;
		while (*col < board.size)
		{
			if (board.self[*row][*col] == UNASSIGNED)
				return (TRUE);
			(*col)++;
		}
		(*row)++;
	}
	return (FALSE);
}

/*
** Check if `building_floor` is already is unique in the row and column
*/

int	is_alone(t_board board, int row, int col, int building_floor)
{
	int i;

	i = 0;
	while (i < board.size)
		if (board.self[row][i++] == building_floor)
			return (FALSE);
	i = 0;
	while (i < board.size)
		if (board.self[i++][col] == building_floor)
			return (FALSE);
	return (TRUE);
}

/*
** Checks if the grid is valid according to the viewpoints
*/

int	check_viewpoints(t_board board, t_views views)
{
	t_view_point	view;
	int				j;

	view = col_up;
	while (view <= row_right)
	{
		j = 0;
		while (j < board.size)
		{
			if (!check_line(board, view, j, views[view][j]))
				return (FALSE);
			j++;
		}
		view++;
	}
	return (TRUE);
}

/*
** Returns TRUE if the number buildings viewed
** with some viewpoint on a line are equal to `building_viewed`.
*/

int	check_line(t_board board, t_view_point view, int view_line,
				int building_viewed)
{
	int	i;
	int	tmp_building_floor;

	i = 0;
	while (i < board.size)
	{
		tmp_building_floor = get_with_view(board, view, view_line, i);
		if (tmp_building_floor == UNASSIGNED)
			return (FALSE);
		building_viewed--;
		while (i + 1 < board.size && tmp_building_floor > get_with_view(
					board, view, view_line, i + 1))
			i++;
		i++;
	}
	return (building_viewed == 0);
}
