/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 18:00:18 by exam              #+#    #+#             */
/*   Updated: 2019/07/12 18:32:44 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int start, int end)
{
	int	*range;
	int	i;

	range = (int*)malloc(sizeof(int) *
						(end - start < 0 ? start - end : end - start + 1));
	if (range == NULL)
		return (NULL);
	i = 0;
	if (start < end)
		while (start <= end)
		{
			range[i] = start;
			start++;
			i++;
		}
	else
		while (start >= end)
		{
			range[i] = start;
			start--;
			i++;
		}
	return (range);
}
