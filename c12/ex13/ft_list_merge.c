/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 08:50:01 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/19 08:51:36 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*cursor;

	cursor = *begin_list1;
	while (cursor->next)
		cursor = cursor->next;
	cursor->next = begin_list2;
}
