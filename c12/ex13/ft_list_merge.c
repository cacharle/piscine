/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 08:50:01 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/23 15:40:47 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*cursor;

	cursor = *begin_list1;
	if (cursor == NULL)
		*begin_list1 = begin_list2;
	while (cursor->next)
		cursor = cursor->next;
	cursor->next = begin_list2;
}
