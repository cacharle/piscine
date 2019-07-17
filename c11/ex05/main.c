/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 07:29:52 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/17 16:37:31 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "include.h"

int	main(int argc, char **argv)
{
	int	x;
	int	y;
	int	operator_index;
	int (*operators[5])(int, int);

	operators[0] = &add;
	operators[1] = &subtract;
	operators[2] = &multiply;
	operators[3] = &divide;
	operators[4] = &modulo;
	operator_index = parse(argc, argv);
	if (operator_index == -1)
		return (0);
	if (operator_index == -2)
		ft_putchar('0');
	else
	{
		x = ft_atoi(argv[1]);
		y = ft_atoi(argv[3]);
		if (operator_index == 3 && y == 0)
		{

		}
		if (operator_index == 3 && y == 0)
		{
		}
		ft_putnbr((*operators[operator_index])(x, y));
	}
	ft_putchar('\n');
	return (0);
}
