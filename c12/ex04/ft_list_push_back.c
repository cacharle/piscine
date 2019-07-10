/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 17:18:46 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/09 17:18:48 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void ft_list_push_back(t_list **begin_list, void *data)
{
	if (*begin_list)
		while (*begin_list->next)
			*begin_list = *begin_list->next;
	elem = ft_create_elem(data);
	if (*begin_list)
		*begin_list->next = elem;
	else
		*begin_list = elem;
}
