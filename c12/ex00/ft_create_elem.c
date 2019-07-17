/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 17:19:22 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/17 18:34:23 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

t_list *ft_create_elem(void *data)
{
	t_list	*list;

	if((list = (t_list*)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	list->data = data;
	list->next = NULL;
	return (list);
}
