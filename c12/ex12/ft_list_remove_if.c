/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 08:38:28 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/23 15:41:03 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref,
						int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*prev;
	t_list	*cursor;
	t_list	*tmp;

	prev = NULL;
	cursor = *begin_list;
	while (cursor != NULL)
	{
		while (cursor && (*cmp)(cursor->data, data_ref) == 0)
		{
			if (prev != NULL)
				prev->next = cursor->next;
			else
				*begin_list = cursor->next;
			(*free_fct)(cursor->data);
			tmp = cursor;
			cursor = cursor->next;
			free(tmp);
		}
		if (cursor != NULL)
		{
			prev = cursor;
			cursor = cursor->next;
		}
	}
}
