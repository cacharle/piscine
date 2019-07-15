/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 16:14:25 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/12 14:41:33 by cacharle         ###   ########.fr       */
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
	int	len;

	len = 0;
	while (size-- > 0)
		len += my_strlen(strs[size]);
	return (len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		j;
	int		k;
	char	*join;

	join = (char*)malloc(sizeof(char) * (cummulative_strlen(size, strs)
						+ my_strlen(sep) * (size - (size == 0 ? 0 : 1) + 1)));
	if (join == NULL)
		return (NULL);
	j = 0;
	k = 0;
	while (k < size)
	{
		i = 0;
		while (strs[k][i])
			join[j++] = strs[k][i++];
		i = 0;
		while (k != size - 1 && sep[i])
			join[j++] = sep[i++];
		k++;
	}
	join[j] = '\0';
	return (join);
}
