/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 07:31:38 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/06 08:36:47 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	pow10(int exponent)
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

int	ft_atoi(char *str)
{
	int	is_negative;
	int	nb;
	int	i;

	while (*str == ' ' || *str == '\t' || *str == '\n'
		   || *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			is_negative = !is_negative;
		str++;
	}
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb += pow10(i) * (str[i] - '0');
		i++;
	}
	if (is_negative)
		nb = -nb;
	return (nb);
}
