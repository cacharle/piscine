/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 17:55:00 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/17 13:09:38 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int		ft_atoi(char *str)
{
	int	is_negative;
	int	nb;
	int	i;
	int	j;

	while (*str == ' ' || *str == '\t' || *str == '\n'
			|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	is_negative = 0;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			is_negative = !is_negative;
		str++;
	}
	nb = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	j = 0;
	while (str[j] >= '0' && str[j] <= '9')
		nb += pow10(--i) * (str[j++] - '0');
	if (is_negative)
		nb = -nb;
	return (nb);
}

int		pow10(int exponent)
{
	int	accumulator;

	accumulator = 1;
	while (exponent > 0)
	{
		accumulator *= 10;
		exponent--;
	}
	return (accumulator);
}
