/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 21:17:12 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/16 21:21:31 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int *ft_map(int *tab, int length, int(*f)(int))
{
	int	i;
	int *mapped;

	if ((mapped = (int*)malloc(sizeof(int) * length)) == NULL)
		return (NULL);
	i = 0;
	while (i < length)
	{
		mapped[i] = (*f)(tab[i]);
		i++;
	}
	return (mapped);
}
