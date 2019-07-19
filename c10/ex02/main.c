/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 14:51:03 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/19 06:58:18 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "include.h"

int		main(int argc, char **argv)
{
	int tail_size;
	int i;
	int status;
	int	good_counter;

	status = 0;
	good_counter = 0;
	tail_size = ft_atoi(argv[2]);
	i = 3;
	if (argc == 3)
		print_file_tail(STDIN_FILENO, tail_size);
	else
		while (i < argc)
		{
			if (print_tail(argv[i], tail_size, argc, good_counter) == -1)
			{
				handle_error(argv[0], argv[i]);
				status = 1;
			}
			else
				good_counter++;
			i++;
		}
	return (status);
}
