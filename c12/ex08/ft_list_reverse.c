/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 18:05:23 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/19 08:18:13 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_list_reverse(t_list **begin_list)
{
	t_list	*cursor;
	t_list	*prev;
	t_list	*tmp_next;

	prev = NULL;
	cursor = *begin_list;
	while (cursor != NULL)
	{
		tmp_next = cursor->next;
		cursor->next = prev;
		prev = cursor;
		cursor = tmp_next;
	}
	*begin_list = prev;
}
