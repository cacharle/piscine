/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 15:23:43 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/24 12:19:39 by samzur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "include.h"

/*
** open the file, pass it to parse_fildes
*/

int	parse_file(char *filename, t_parsed_terrain *pterrain)
{
	int		fildes;

	if ((fildes = open(filename, O_RDONLY)) < 0)
		return (-1);
	if (parse_fildes(fildes, pterrain) < 0)
	{
		close(fildes);
		return (-1);
	}
	if (close(fildes) < 0)
		return (-1);
	return (0);
}

/*
** read file designated by fildes in `file`, pass it to parse,
** free the file string
** return -1 in case of error, 0 otherwise
*/

int	parse_fildes(int fildes, t_parsed_terrain *pterrain)
{
	char	*file;

	if ((file = read_file(fildes)) == NULL)
		return (-1);
	if (parse(file, pterrain) < 0)
	{
		free(file);
		return (-1);
	}
	free(file);
	return (0);
}

/*
** parse the file string, initialise pterrain attributes
** return -1 in case of error, 0 otherwise
*/

int	parse(char *file, t_parsed_terrain *pterrain)
{
	int	y;
	int	i;

	if ((pterrain->terrain = (t_terrain*)malloc(sizeof(t_terrain))) == NULL)
		return (-1);
	if ((i = parse_header(file, pterrain)) < 0)
	{
		free(pterrain->terrain);
		return (-1);
	}
	if (set_dimensions(&file[i], pterrain) < 0 || (pterrain->terrain->matrix =
		(int**)malloc(sizeof(int*) * pterrain->terrain->rows)) == NULL)
	{
		free(pterrain->terrain);
		return (-1);
	}
	y = -1;
	while (++y < pterrain->terrain->rows)
		if ((pterrain->terrain->matrix[y] = set_row(file, pterrain, y)) == NULL)
		{
			destroy_terrain(pterrain->terrain);
			free(pterrain);
			return (-1);
		}
	return (0);
}
