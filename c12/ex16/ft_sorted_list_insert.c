/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 08:19:32 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/23 15:44:40 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list *cursor;
	t_list *elem;

	cursor = *begin_list;
	elem = ft_create_elem(data);
	if (cursor == NULL)
	{
		*begin_list = elem;
		return ;
	}
	if ((*cmp)(elem->data, cursor->data) < 0)
	{
		elem->next = cursor;
		*begin_list = elem;
		return ;
	}
	while (cursor->next && (*cmp)(elem->data, cursor->next->data) > 0)
		cursor = cursor->next;
	elem->next = cursor->next;
	cursor->next = elem;
}
