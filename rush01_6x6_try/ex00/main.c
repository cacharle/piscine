/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 11:30:35 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/14 10:24:10 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "include.h"

#include <string.h>
#include <stdio.h>
int	main(int argc, char ** argv)
{
	t_views views;
	t_board board;

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	/*int tb[4][4] = {*/
		/*{1, 2, 3, 4},*/
		/*{2, 3, 4, 1},*/
		/*{3, 4, 1, 2},*/
		/*{4, 1, 2, 3}*/
	/*};*/
	views = parse_arg(argv[1]);
	/*print_square(views);*/
	board = init_square(4);
	/*memcpy(board[0], tb[0], sizeof(int) * 4);*/
	/*memcpy(board[1], tb[1], sizeof(int) * 4);*/
	/*memcpy(board[2], tb[2], sizeof(int) * 4);*/
	/*memcpy(board[3], tb[3], sizeof(int) * 4);*/
	/*print_square(board);*/
	/*printf("check views %d\n", check_viewpoints(board, views));*/
	/*print_square(board);*/
	/*printf("%d\n", get_with_view(board, col_down, 0, 2));*/
	/*ft_putchar('\n');*/
	solve(board, views);
	/*ft_putchar('\n');*/
	/*board = init_square(4);*/
	/*board[0][0] = 2;*/
	/*ft_putchar('\n');*/
	/*print_square(board);*/
	/*solve(board);*/
	/*ft_putchar('\n');*/
	/*print_square(board);*/
	return (0);
}
