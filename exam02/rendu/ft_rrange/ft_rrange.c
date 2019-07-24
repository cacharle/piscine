/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 18:05:29 by exam              #+#    #+#             */
/*   Updated: 2019/07/19 19:59:56 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

long unsigned int	get_size(int start, int end)
{
	long unsigned int	size;

	if (start < end)
		size = (long int)end - (long int)start;
	else if (start > end)
		size = (long int)start - (long int)end;
	else
		size = 0;
	return (size);
}

int	*ft_rrange(int start, int end)
{
	int	*rrange;
	long unsigned int	i;

	if ((rrange = (int*)malloc(sizeof(int) * (get_size(start, end) + 1))) == NULL)
		return (NULL);
	rrange[0] = end;
	if (start == end)
		return (rrange);
	i = 0;
	while (end != start)
	{
		rrange[i] = end;
		end += (end < start ? 1 : -1);
		i++;
	}
	rrange[i] = start;
	return (rrange);	
}
