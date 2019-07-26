/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 16:42:44 by exam              #+#    #+#             */
/*   Updated: 2019/07/26 17:43:25 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdlib.h>
#include <unistd.h>

void	go_close(char **str)
{
	t_stack *st;

	st = create_elem(**str);
	while (st != NULL)
	{
		(*str)++;
		if (**str == '[')
			st = push(st, '[');
		if (**str == ']')
			st = pop(st);
	}
}

void	go_open(char **str)
{
	t_stack *st;

	st = create_elem(**str);
	while (st != NULL)
	{
		(*str)--;
		if (**str == ']')
			st = push(st, ']');
		if (**str == '[')
			st = pop(st);
	}
}

int	main(int argc, char **argv)
{
	char	*ptr;
	char	*origin;
	char	*str;
	int		i;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	origin = (char*)malloc(2048);
	ptr = origin;
	i = 0;
	while (i < 2048)
		ptr[i++] = 0;
	str = argv[1];
	while (*str)
	{
		if (*str == '>')
			ptr++;
		else if (*str == '<')
			ptr--;
		else if (*str == '+')
			(*ptr)++;
		else if (*str == '-')
			(*ptr)--;
		else if (*str == '.')
			write(1, ptr, 1);
		else if (*str == '[' && *ptr == 0)
			go_close(&str);
		else if (*str == ']' && *ptr != 0)
			go_open(&str);
		str++;
	}
	free(origin);
	return (0);
}
