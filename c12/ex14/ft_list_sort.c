/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 13:43:11 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/19 13:53:54 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	is_sorted(t_list **begin_list, int (*cmp)())
{
	t_list	*cursor;

	while (cursor->next)
	{
		if ((*cmp)(cursor->data, cursor->next->data) > 0)
			return (0);
		cursor = cursor->next;
	}
	return (1);
}

void ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*cursor;
	void	*tmp;

	while (!is_sorted(*begin_list, cmp))
	{
		cursor = *begin_list;
		while (cursor->next)
		{
			if ((*cmp)(cursor->data, cursor->next->data) > 0)
			{
				tmp = cursor->data;
				cursor->data = cursor->data->next;
				cursor->data->next = tmp;
			}
			cursor = cursor->next;
		}
	}
}
