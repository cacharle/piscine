/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 08:38:28 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/19 08:49:43 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*prev;
	t_list	*cursor;

	prev = NULL;
	cursor = *begin_list;
	while (cursor)
	{
		if ((*cmp)(cursor->data, data_ref))
		{
			if (prev)
				prev->next = cursor->next;
			(*free_fct)(cursor->data);
		}
		cursor = cursor->next;
	}
}
