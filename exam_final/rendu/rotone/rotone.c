/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 10:15:47 by exam              #+#    #+#             */
/*   Updated: 2019/07/26 10:27:46 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_upper(char c)
{
	return (c >= 'A' && c <= 'Z');
}

int is_lower(char c)
{
	return (c >= 'a' && c <= 'z');
}

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc == 2)
	{
		i = 0;
		while (argv[1][i])
		{
			if (is_lower(argv[1][i]))
				ft_putchar((argv[1][i] - 'a' + 1) % 26 + 'a');
			else if (is_upper(argv[1][i]))
				ft_putchar((argv[1][i] - 'A' + 1) % 26 + 'A');
			else
				ft_putchar(argv[1][i]);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
