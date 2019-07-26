/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 15:20:07 by exam              #+#    #+#             */
/*   Updated: 2019/07/26 16:29:42 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "include.h"

int		sorted(char **strs, int cmp(char*, char*))
{
	int	i;

	i = 0;
	if (strs[0] == NULL)
		return (1);
	while (strs[i + 1] != NULL)
	{
		if ((*cmp)(strs[i], strs[i + 1]) > 0)
			return (0);
		i++;
	}
	return (1);
}

void	sort_strs(char **strs, int cmp(char*, char*))
{
	int		i;
	char	*tmp;

	while (!sorted(strs, cmp))
	{
		i = 0;
		while (strs[i + 1] != NULL)
		{
			if ((*cmp)(strs[i], strs[i + 1]) > 0)
			{
				tmp = strs[i];
				strs[i] = strs[i + 1];
				strs[i + 1] = tmp;
			}
			i++;
		}
	}
}

int		strlen_cmp(char *s1, char *s2)
{
	return (ft_strlen(s1) - ft_strlen(s2));
}

void	print_strs(char **strs)
{
	int	i;
	int	len;

	i = 0;
	while (strs[i] != NULL)
	{
		len = ft_strlen(strs[i]);
		while (strs[i] && ft_strlen(strs[i]) == len)
		{
			ft_putstr(strs[i]);
			if (strs[i + 1] != NULL && ft_strlen(strs[i + 1]) == len)
				ft_putstr(" ");
			else
				ft_putstr("\n");
			i++;
		}
	}
}
