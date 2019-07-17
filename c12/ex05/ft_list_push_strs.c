/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 17:18:23 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/17 18:34:23 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	list_push_front(t_list **begin_list, void *data)
{
	t_list	*new_front;

	new_front = ft_create_elem(data);
	new_front->next = *begin_list;
	*begin_list = new_front;
}

t_list	*ft_list_push_strs(int size, char **strs)
{
	int	i;
	t_list	*list;

	list = NULL;
	i = 0;
	while (i < size)
		list_push_front(&list, strs[i++]);
	return (list);
}
