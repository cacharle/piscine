/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 20:02:01 by exam              #+#    #+#             */
/*   Updated: 2019/07/19 20:46:03 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*cursor;
	t_list	*prev;

	if (!*begin_list)
		return ;
	while (*begin_list && (*cmp)(data_ref, (*begin_list)->data))
		*begin_list = (*begin_list)->next;
	cursor = *begin_list;
	prev = NULL;
	while (cursor)
	{
		while (cursor && (*cmp)(data_ref, cursor->data))
		{
			if (prev != NULL)
				prev->next = cursor->next;
			cursor = cursor->next;
		}
		prev = cursor;
		if (cursor)
			cursor = cursor->next;
	}
}
