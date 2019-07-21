/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 13:55:34 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/20 08:18:04 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static t_list	*reverse_rec(t_list *begin_list)
{
	if (!begin_list)
		return begin_list;
	if (!begin_list->next)
		return begin_list;
	ft_list_reverse_fun(begin_list->next);
	begin_list->next->next = begin_list;
	begin_list->next = NULL;
}

void ft_list_reverse_fun(t_list *begin_list)
{
	begin_list = reverse_rec(begin_list);
}
