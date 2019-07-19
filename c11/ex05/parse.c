/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 08:05:59 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/18 10:40:34 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	parse(int argc, char **argv)
{
	int i;

	if (argc != 4)
		return (-1);
	if (argv[2][0] == '+')
		i = 0;
	else if (argv[2][0] == '-')
		i = 1;
	else if (argv[2][0] == '*')
		i = 2;
	else if (argv[2][0] == '/')
		i = 3;
	else if (argv[2][0] == '%')
		i = 4;
	else
		i = -2;
	return (i);
}

int	check_floating_point_error(int operator_index, int y)
{
	if (operator_index == 3 && y == 0)
	{
		write(1, "Stop : division by zero\n", 24);
		return (-1);
	}
	if (operator_index == 4 && y == 0)
	{
		write(1, "Stop : modulo by zero\n", 22);
		return (-1);
	}
	return (0);
}
