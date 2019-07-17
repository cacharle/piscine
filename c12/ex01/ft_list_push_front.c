/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 17:19:14 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/17 17:10:46 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*new_front;

	new_front = ft_create_elem(data);
	new_front->next = *begin_list;
	*begin_list = new_front;
}
