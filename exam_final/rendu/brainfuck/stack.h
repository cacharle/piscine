/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 17:33:37 by exam              #+#    #+#             */
/*   Updated: 2019/07/26 17:39:15 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

typedef struct	s_stack
{
	char			data;
	struct	s_stack	*next;
}				t_stack;

t_stack *push(t_stack *stack, char data);
t_stack *create_elem(char data);
t_stack *pop(t_stack *stack);

#endif
