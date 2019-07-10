/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 17:18:23 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/09 17:52:44 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_push_strs(int size, char **strs)
{
	int	i;
	t_list	elem;
	t_list	next;

	next = NULL;
	i = 0;
	while (i < size)
	{
		elem = ft_create_elem(strs[i]);
		elem->next = next;
		next = elem;
	}
	return (&elem);
}
