/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 08:13:44 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/23 16:09:19 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

static void	sorted_list_insert(t_list **begin_list, t_list *elem, int (*cmp)())
{
	t_list	*cursor;

	cursor = *begin_list;
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

void		ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2,
									int (*cmp)())
{
	while (begin_list2)
	{
		printf("%d\n", *(int*)begin_list2->data);
		begin_list2 = begin_list2->next;
		sorted_list_insert(begin_list1, begin_list2, cmp);
	}
}
