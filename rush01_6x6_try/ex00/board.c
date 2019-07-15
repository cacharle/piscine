/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 13:23:16 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/14 13:31:15 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

/*void	fill_clue1n(t_board board, t_views views)*/
/*{*/
	/*int	i;*/
	/*int	j;*/

	/*i = 0;*/
	/*while (i < 4)*/
	/*{*/
		/*j = 0;*/
		/*while (j < 4)*/
		/*{*/
			/*if (views[i][j] == 1)*/
				/*line_at(i);*/

		/*}*/
	/*}*/
/*}*/

/*int *line_at(t_board board, t_view_side side, int line_index);*/
/*{*/
	/*int *line;*/
	/*int	i;*/

	/*line = malloc(sizeof(int) * 4);*/
	/*i = 0*/
	/*if (side == row_left)*/
		/*while (i < 4)*/
			/*line[i] = board[line_index][i++];*/
	/*if (side == row_right)*/
		/*while (i < 4)*/
			/*line[i] = board[line_index][size - i++];*/
	/*if (side == col_up)*/
		/*while (i < 4)*/
			/*line[i] = board[line_index][i++];*/



/*}*/

/*void set_at(t_board board, t_view_side side, int side_index, int line_index, int value)*/
/*{*/
	/*if (side == row_left)*/
		/*board[side_index][line_index] = value;*/
	/*if (side == row_right)*/
		/*board[side_index][3 - line_index] = value;*/
	/*if (side == col_up)*/
		/*board[line_index][side_index] = value;*/
	/*if (side == col_down)*/
		/*board[3 - line_index][side_index] = value;*/
/*}*/

int	get_with_view(t_board board, t_view_point view, int view_line, int line_index)
{
	if (view == row_left)
		return board.self[view_line][line_index];
	if (view == row_right)
		return board.self[view_line][board.size - 1 - line_index];
	if (view == col_up)
		return board.self[line_index][view_line];
	if (view == col_down)
		return board.self[board.size - 1 - line_index][view_line];
	return (-1);
}
