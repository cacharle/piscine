/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 17:25:25 by exam              #+#    #+#             */
/*   Updated: 2019/07/12 17:57:14 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	in_charset(char c, char *charset)
{
	while (*charset)
		if (c == *charset++)
			return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	char	*str;
	char	*charset;

	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	str = argv[1];
	charset = argv[2];
	i = 0;
	j = 0;
	while (str[i])
	{
		if (!in_charset(str[i], charset))
		{
			write(1, "\n", 1);
			return (0);
		}
		while (*charset != str[i])
			charset++;
		i++;
	}
	while (*str)
		write(1, str++, 1);
	write(1, "\n", 1);
	return (0);
}
