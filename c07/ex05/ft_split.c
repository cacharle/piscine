/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:58:03 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/09 12:42:21 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		in_charset(char character, char *charset)
{
	while (*charset)
		if (character == *charset++)
			return (1);
	return (0);
}

int		count_segment(char *str, char *charset)
{
	int	counter;

	counter = 1;
	while (*str)
	{
		if (in_charset(*str, charset))
			counter++;
		str++;
	}
	return (counter);
}

char	**ft_split(char *str, char *charset)
{
	char	**strs;
	char	*tmp;
	int		i;
	int		j;
	int		k;

	strs = (char**)malloc(sizeof(char*) * (count_segment(str, charset) + 1));
	printf("%d\n", count_segment(str, charset));
	k = 0;
	while (*str)
	{
		i = 0;
		while (!in_charset(str[i], charset))
			i++;
		tmp = (char*)malloc(sizeof(char) * i);
		if (tmp == NULL)
			printf("bonjour");
		i = 0;
		while (!in_charset(*str, charset))
			tmp[i++] = *str++;
		strs[k++] = tmp;
		str++;
	}
	strs[k] = 0;
	return (strs);
}
