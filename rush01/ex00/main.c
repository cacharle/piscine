/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 11:30:35 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/14 22:36:55 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "include.h"

int	main(int argc, char **argv)
{
	t_views views;
	t_board board;
	int		solved;

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (!check_arg(argv[1]))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	views = parse_arg(argv[1]);
	board = init_square(4);
	solved = FALSE;
	solve(board, views, &solved);
	if (!solved)
		write(1, "Error\n", 6);
	return (0);
}
