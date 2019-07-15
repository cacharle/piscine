/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 12:07:59 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/14 13:22:42 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_H
# define INCLUDE_H

//typedef int** t_board;
//typedef int** t_board;

typedef enum
{
	col_up,
	col_down,
	row_left,
	row_right
}	t_view_point;
typedef struct
{
	int	size;
	int **self;
}	t_square;
typedef t_square t_board;
typedef t_square t_views;

int		solve(t_board board, t_views views);
int		find_next_unassigned(t_board board, int *row, int *col);
int		is_alone(t_board board, int bfloor, int row, int col);
int		check_viewpoints(t_board board, t_views views);
int		check_line(t_board board, t_view_point view, int view_line,
			int building_viewed);
t_views	parse_arg(char *arg);
int		**init_square(int size);
int		**dup_square(int **square);
void	destroy_square(int **square);
void	print_square(t_board board);
int		get_with_view(t_board board, t_view_point view, int view_line,
			int line_index);
void	ft_putchar(char c);
void	ft_putnbr(int nb);

#endif
