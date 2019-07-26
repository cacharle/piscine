/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 17:28:55 by exam              #+#    #+#             */
/*   Updated: 2019/07/26 17:40:35 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "stack.h"

t_stack *create_elem(char data)
{
	t_stack *elem;

	elem = malloc(sizeof(t_stack));
	elem->data = data;
	elem->next = NULL;
	return (elem);
}

t_stack *push(t_stack *stack, char data)
{
	t_stack *elem;

	elem = create_elem(data);
	elem->next = stack;
	return (elem);
}

t_stack *pop(t_stack *stack)
{
	t_stack *tmp;

	tmp = stack->next;
	free(stack);
	return (tmp);
}
