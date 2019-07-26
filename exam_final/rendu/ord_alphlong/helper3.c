/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 16:34:01 by exam              #+#    #+#             */
/*   Updated: 2019/07/26 16:34:28 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "include.h"

int		in_charset(char c)
{
	return (c == ' ' || c == '\t');
}

int		count_segment(char *str)
{
	int	counter;

	counter = 0;
	while (*str)
	{
		if (in_charset(*str))
		{
			str++;
			continue ;
		}
		counter++;
		while (*str && !in_charset(*str))
			str++;
	}
	return (counter);
}

char    **ft_split(char *str)
{
	char	**strs;
	char	*tmp;
	int		size;
	int		i;
	int		j;

	size = count_segment(str);
	if ((strs = (char**)malloc(sizeof(char*) * (size + 1))) == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		if (*str && in_charset(*str))
		{
			str++;
			continue ;
		}
		j = 0;
		while (str[j] && !in_charset(str[j]))
			j++;
		if ((tmp = (char*)malloc(sizeof(char) * (j + 1))) == NULL)
			return (NULL);
		j = 0;
		while (*str && !in_charset(*str))
		{
			tmp[j] = *str++;
			j++;
		}
		tmp[j] = '\0';
		strs[i++] = tmp;
	}
	strs[i] = NULL;
	return (strs);
}
