/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 08:31:11 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/19 08:34:48 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_list_foreach_if(t_list *begin_list, void (*f)(void *), void
		*data_ref, int (*cmp)())
{
	while (begin_list != NULL)
		if ((*cmp)(begin_list->data, data_ref) == 0)
			(*f)(begin_list->data);
}
