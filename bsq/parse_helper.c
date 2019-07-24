/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 19:24:06 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/24 12:04:33 by samzur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "include.h"

/*
** initialise the `y` row of the matrix
*/

int	*set_row(char *file, t_parsed_terrain *pterrain, int y)
{
	int	i;
	int	x;
	int	*row;

	if ((row = (int*)malloc(sizeof(int) * pterrain->terrain->columns)) == NULL)
		return (NULL);
	i = ft_line_len(file) + 1;
	i += (ft_line_len(&file[i]) + 1) * y;
	x = 0;
	while (x < pterrain->terrain->columns)
	{
		if (file[i] == pterrain->empty)
			row[x] = EMPTY;
		else if (file[i] == pterrain->obstacle)
			row[x] = OBSTACLE;
		i++;
		x++;
	}
	return (row);
}

/*
** set dimensions of the terrain and check they correspond with the terrain,
** also check the character used for the cell types
** return -1 in case of error, 0 otherwise.
*/

int	set_dimensions(char *file, t_parsed_terrain *pterrain)
{
	int	i;
	int	j;
	int	first_line_len;
	int	line_len;

	first_line_len = ft_line_len(file);
	if (first_line_len == 0)
		return (-1);
	i = 0;
	while (file[i])
	{
		line_len = ft_line_len(&file[i]);
		if (line_len != first_line_len)
			return (-1);
		j = -1;
		while (++j < line_len)
			if (file[i + j] != pterrain->empty
				&& file[i + j] != pterrain->obstacle)
				return (-1);
		i += line_len + 1;
	}
	pterrain->terrain->columns = first_line_len;
	return (0);
}

/*
** Parse header and check if everything is ok (number, obstacles, duplicates)
*/

int	parse_header(char *file, t_parsed_terrain *pterrain)
{
	int	i;

	i = ft_line_len(file);
	if (i < 4)
		return (-1);
	pterrain->filled = file[--i];
	pterrain->obstacle = file[--i];
	pterrain->empty = file[--i];
	if (pterrain->filled == pterrain->obstacle
		|| pterrain->filled == pterrain->empty
		|| pterrain->obstacle == pterrain->empty)
		return (-1);
	if ((pterrain->terrain->rows = ft_natoi(file, i)) < 0)
		return (-1);
	i = ft_line_len(file) + 1;
	if (pterrain->terrain->rows != count_lines(&file[i])
		|| pterrain->terrain->rows == 0)
		return (-1);
	return (i);
}
