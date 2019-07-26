/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 10:42:10 by exam              #+#    #+#             */
/*   Updated: 2019/07/26 11:05:51 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	counter;

	counter = 0;
	while (str[counter])
		counter++;
	return (counter);
}

int	is_space(char c)
{
	return (c == ' ' || c == '\t');
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc == 2)
	{
		i = ft_strlen(argv[1]) - 1;
		while (i > -1 && is_space(argv[1][i]))
			i--;
		while (i > -1 && !is_space(argv[1][i]))
			i--;
		i++;
		while (i >= 0 && argv[1][i] && !is_space(argv[1][i]))
		{
			write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
