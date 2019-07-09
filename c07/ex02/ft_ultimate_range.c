/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 16:09:06 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/09 07:46:19 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	*range = (int*)malloc(sizeof(int) * (max - min));
	if (*range == NULL)
		return (-1);
	i = 0;
	while (i < max - min)
	{
		(*range)[i] = min + i;
		i++;
	}
	return (i);
}
