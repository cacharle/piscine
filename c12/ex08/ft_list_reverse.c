/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 18:05:23 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/17 19:13:19 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_list_reverse(t_list **begin_list)
{
	t_list	*tmp;
	t_list	*prev;

	prev = NULL;
	tmp = (*begin_list)->next;
	while (tmp != NULL)
	{
		(*begin_list)->next = prev;
		prev = *begin_list;
		*begin_list = tmp;
		tmp = (*begin_list)->next;
	}
}
