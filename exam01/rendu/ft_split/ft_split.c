/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 18:35:38 by exam              #+#    #+#             */
/*   Updated: 2019/07/12 19:27:00 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#define ISSEP(c) (c == ' ' || c == '\n' || c == '\t')

int		count_segment(char *str)
{
	int counter;

	counter = 0;
	while (*str)
	{
		if (!ISSEP(*str))
		{
			counter++;
			while (*str && !ISSEP(*str))
				str++;
			if (!*str)
				break;
		}
		str++;
	}
	return (counter);
}

char	**ft_split(char *str)
{
	char **split;
	char *tmp;
	int i;
	int j;
	int segments;

	segments = count_segment(str);
	split = (char**)malloc(sizeof(char*) * segments + 1);
	if (split == NULL)
		return (NULL);
	j = 0;
	while (j < segments)
	{
		if (ISSEP(*str))
		{
			str++;
			continue;
		}
		i = 0;
		while (!ISSEP(str[i]))
			i++;
		tmp = (char*)malloc(sizeof(char) * i + 1);
		if (tmp == NULL)
			return (NULL);
		i = 0;
		while (!ISSEP(*str))
			tmp[i++] = *str++;
		tmp[i] = '\0';
		split[j] = tmp;
		j++;
	}
	split[j] = NULL;
	return (split);
}
