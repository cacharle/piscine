/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 17:19:06 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/09 17:19:07 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int	counter;

	counter = 0;
	while (begin_list)
	{
		counter++;
		begin_list = begin_list->next;
	}
	return (counter);
}
