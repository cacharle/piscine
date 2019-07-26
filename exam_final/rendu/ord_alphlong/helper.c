/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 14:40:48 by exam              #+#    #+#             */
/*   Updated: 2019/07/26 16:35:08 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "include.h"

int		ft_strlen(char *str)
{
	int counter;

	counter = 0;
	while (str[counter])
		counter++;
	return (counter);
}

int		letter_diff(char a, char b)
{
	if (b >= 'A' && b <= 'Z')
		b += 'a' - 'A';
	if (a >= 'A' && a <= 'Z')
		a += 'a' - 'A';
	return (a - b);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int		str_lettercmp(char *s1, char *s2)
{
	if (ft_strlen(s1) != ft_strlen(s2))
		return (-1);
	while (*s1 && *s2 && letter_diff(*s1, *s2) == 0)
	{
		s1++;
		s2++;
	}
	return (letter_diff(*s1, *s2));
}
