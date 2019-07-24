/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 17:46:19 by exam              #+#    #+#             */
/*   Updated: 2019/07/19 18:03:23 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	pow10(int exponent)
{
	int	acc;

	acc = 1;
	while (exponent > 0)
	{
		acc *= 10;
		exponent--;
	}
	return (acc);
}


int	ft_atoi(const char *str)
{
	int	nb;
	int i;
	int j;
	int	is_negative;

	nb = 0;
	while (*str == ' ' | *str == '\t' || *str == '\n' || *str == '\v'
			|| *str == '\f' || *str == '\r')
		str++;
	is_negative = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			is_negative = 1;
		str++;
	}
	j = 0;
	while (str[j] >= '0' && str[j] <= '9')
		j++;
	j--;
	i = 0;
	while (j >= 0)
	{
		nb += (str[j] - '0') * pow10(i);
		i++;
		j--;
	}
	if (is_negative)
		nb = -nb;
	return (nb);
}
