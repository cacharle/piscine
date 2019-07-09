/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 16:14:25 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/09 09:08:52 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		my_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		cummulative_strlen(int size, char **strs)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	while (size > 0)
	{
		len += my_strlen(strs[size - 1]);
		size--;
	}
	return (len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		j;
	int		k;
	int		l;
	char	*join;

	join = (char*)malloc(sizeof(char) * (cummulative_strlen(size, strs)
							+ my_strlen(sep) * (size - 1) + 1));
	j = 0;
	l = 0;
	while (l < size)
	{
		i = 0;
		while (strs[l][i])
		{
			join[j] = strs[l][i];
			i++;
			j++;
		}
		k = 0;
		while (l != size - 1 && sep[k])
			join[j++] = sep[k++];
		l++;
	}
	return (join);
}
