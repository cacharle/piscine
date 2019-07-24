/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 17:18:46 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/23 15:42:15 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*new_rear;
	t_list	*cursor;

	new_rear = ft_create_elem(data);
	if (*begin_list == NULL)
	{
		*begin_list = new_rear;
		return ;
	}
	cursor = *begin_list;
	while (cursor->next)
		cursor = cursor->next;
	cursor->next = new_rear;
}
