/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 19:19:56 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/24 14:50:31 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "include.h"

/*
** Solve terrain (from Stdin), print and free it when it's done
*/

void	parse_stdin_print(void)
{
	t_parsed_terrain	*pterrain;

	pterrain = malloc(sizeof(t_parsed_terrain));
	if (parse_fildes(STDIN_FILENO, pterrain) < 0)
		write(STDOUT_FILENO, "map error\n", 10);
	else
	{
		solve_and_complete(pterrain->terrain);
		print_terrain(pterrain);
		destroy_terrain(pterrain->terrain);
	}
	free(pterrain);
}

/*
** Solve terrain (from a file), print and free it when it's done
*/

void	parse_file_print(char *filename)
{
	t_parsed_terrain	*pterrain;

	pterrain = malloc(sizeof(t_parsed_terrain));
	if (parse_file(filename, pterrain) < 0)
		write(STDOUT_FILENO, "map error\n", 10);
	else
	{
		solve_and_complete(pterrain->terrain);
		print_terrain(pterrain);
		destroy_terrain(pterrain->terrain);
	}
	free(pterrain);
}

/*
** count the number of line of a file
*/

int		count_lines(char *file)
{
	int	counter;

	counter = 0;
	while (*file)
	{
		if (*file == '\n')
			counter++;
		file++;
	}
	return (counter);
}

/*
** strlen until '\n' or '\0'
*/

int		ft_line_len(char *str)
{
	int counter;

	counter = 0;
	while (str[counter] && str[counter] != '\n')
		counter++;
	return (counter);
}
