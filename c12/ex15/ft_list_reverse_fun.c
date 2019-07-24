/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 13:55:34 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/23 15:44:23 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

static t_list	*my_at(t_list *begin_list, int nbr)
{
	while (nbr-- > 0 && begin_list != NULL)
		begin_list = begin_list->next;
	return (begin_list);
}

static int		my_size(t_list *begin_list)
{
	int	counter;

	counter = 0;
	while (begin_list->next)
	{
		counter++;
		begin_list = begin_list->next;
	}
	return (counter);
}

void			ft_list_reverse_fun(t_list *begin_list)
{
	void			*tmp;
	unsigned int	j;
	unsigned int	i;

	j = my_size(begin_list);
	i = 0;
	while (i < j)
	{
		tmp = my_at(begin_list, i)->data;
		my_at(begin_list, i)->data = my_at(begin_list, j)->data;
		my_at(begin_list, j)->data = tmp;
		i++;
		j--;
	}
}
