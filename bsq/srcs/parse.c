/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 15:23:43 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/19 15:55:31 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

t_bool check_input(char *input)
{
	char *line;
	int		i;

	i = 0;
	while (input[i] != '\n')
		i++;
	if (i < 4)
		return (FALSE);
	parsed.fill = input[i--];
	parsed.obstacle = input[i--];
	parsed.empty = input[i--];
	// parsed.size = // atoi smth
	while (*input != '\n')
		input++;
	i = 0;
	while (input[i])
	{
		while (input[i] != '\n')
		{

		}
		if (i != parsed.size


	}
}
