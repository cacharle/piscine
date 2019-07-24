/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 17:20:35 by exam              #+#    #+#             */
/*   Updated: 2019/07/19 17:44:03 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	already_checked(char *str, int index)
{
	char tested;

	tested = str[index];
	while (index-- > 0)
		if (str[index] == tested)
			return (1);
	return (0);
}

int	inside(char *str, char c)
{
	while (*str)
	{
		if (c == *str)
			return (1);
		str++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	char	*str1;
	char	*str2;
	int		i;

	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	str1 = argv[1];
	str2 = argv[2];
	while (str1[i])
	{
		if (already_checked(str1, i))
		{
			i++;
			continue ;
		}
		if (inside(str2, str1[i]))
			write(1, &str1[i], 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
