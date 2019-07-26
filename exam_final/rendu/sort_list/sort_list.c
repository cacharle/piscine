/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 13:11:16 by exam              #+#    #+#             */
/*   Updated: 2019/07/26 13:33:27 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "list.h"

static int	sorted(t_list *lst, int (*cmp)(int, int))
{
	if (lst == NULL)
		return (1);
	while (lst->next != NULL)
	{
		if ((*cmp)(lst->data, lst->next->data) == 0)
			return (0);
		lst = lst->next;
	}
	return (1);
}

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	t_list	*cursor;
	int		tmp;

	while (!sorted(lst, cmp))
	{
		cursor = lst;
		while (cursor->next != NULL)
		{
			if ((*cmp)(cursor->data, cursor->next->data) == 0)
			{
				tmp = cursor->data;
				cursor->data = cursor->next->data;
				cursor->next->data = tmp;
			}
			cursor = cursor->next;
		}
	}
	return (lst);
}
