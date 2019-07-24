/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terrain.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 08:56:45 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/24 12:06:11 by samzur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "include.h"

/*
** Free the terrain
*/

void	destroy_terrain(t_terrain *terrain)
{
	int y;

	if (terrain == NULL)
		return ;
	if (terrain->matrix == NULL)
		return ;
	y = 0;
	while (y < terrain->rows)
	{
		if (terrain->matrix[y] == NULL)
			break ;
		free(terrain->matrix[y++]);
	}
	free(terrain->matrix);
}

void	print_terrain(t_parsed_terrain *pterrain)
{
	int		terrain_len;
	char	*terrain_str;

	terrain_str = (char*)malloc(sizeof(char) * pterrain->terrain->rows
						* (pterrain->terrain->columns + 1));
	terrain_len = terrain_to_string(pterrain, terrain_str);
	write(STDOUT_FILENO, terrain_str, terrain_len);
	free(terrain_str);
}

int		terrain_to_string(t_parsed_terrain *pterrain, char *str)
{
	int	i;
	int j;
	int	str_index;

	str_index = 0;
	i = 0;
	while (i < pterrain->terrain->rows)
	{
		j = 0;
		while (j < pterrain->terrain->columns)
		{
			if (pterrain->terrain->matrix[i][j] >= EMPTY)
				str[str_index] = pterrain->empty;
			else if (pterrain->terrain->matrix[i][j] == OBSTACLE)
				str[str_index] = pterrain->obstacle;
			else if (pterrain->terrain->matrix[i][j] == FILLED)
				str[str_index] = pterrain->filled;
			j++;
			str_index++;
		}
		i++;
		str[str_index] = '\n';
		str_index++;
	}
	return (str_index);
}
