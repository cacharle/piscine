/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 17:18:46 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/17 18:04:28 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*new_rear;

	new_rear = ft_create_elem(data);
	if (!*begin_list)
	{
		(*begin_list) = new_rear;
		return ;
	}
	while ((*begin_list)->next)
		*begin_list = (*begin_list)->next;
	(*begin_list)->next = new_rear;
}
