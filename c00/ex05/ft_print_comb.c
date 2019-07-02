/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 22:55:29 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/02 23:14:29 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void);

void	write_xyz_comb(int x, int y, int z)
{
	char	x_char;
	char	y_char;
	char	z_char;

	x_char = x + '0';
	y_char = y + '0';
	z_char = z + '0';
	write(1, &x_char, 1);
	write(1, &y_char, 1);
	write(1, &z_char, 1);
}

void	ft_print_comb(void)
{
	char	x;
	char	y;
	char	z;

	x = 0;
	y = 0;
	z = 0;
	while (x < 10)
	{
		while (y < 10)
		{
			while (z < 10)
			{
				if (x != y && x != z && y != z)
					write_xyz_comb(x, y, z);
				z++;
			}
			y++;
		}
		x++;
	}
}

int		main(void)
{
	ft_print_comb();
	return (0);
}

