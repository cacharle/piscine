/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 17:12:59 by exam              #+#    #+#             */
/*   Updated: 2019/07/12 17:21:12 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		main(int argc, char **argv)
{
	if (argc == 1 || argc > 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	while (*argv[1])
	{
		if (*argv[1] >= 'a' && *argv[1] <= 'z')
			ft_putchar(*argv[1] == 'z' ? 'a' : *argv[1] + 1);
		else if (*argv[1] >= 'A' && *argv[1] <= 'Z')
			ft_putchar(*argv[1] == 'Z' ? 'A' : *argv[1] + 1);
		else
			ft_putchar(*argv[1]);
		argv[1]++;
	}
	write(1, "\n", 1);
	return (0);
}
