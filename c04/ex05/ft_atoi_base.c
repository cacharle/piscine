/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 08:07:17 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/07 13:26:28 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_the_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+' || base[i] == ' '
			|| base[i] == '\t' || base[i] == '\n' || base[i] == '\v'
			|| base[i] == '\f' || base[i] == '\r')
			return (0);
		j = 0;
		while (base[j])
		{
			if (j != i && base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (1);
}

int	my_pow(int base, int exponent)
{
	int	accumulator;

	accumulator = 1;
	while (exponent > 0)
	{
		accumulator *= base;
		exponent--;
	}
	return (accumulator);
}

int	position_in_base(char digit, char *base)
{
	int	i;

	i = 0;
	while (base[i] != digit)
		i++;
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int	radix;
	int	i;
	int	j;
	int	nb;

	if (!check_the_base(base))
		return (0);
	nb = 0;
	radix = 0;
	while (base[radix])
		radix++;
	i = 0;
	while (str[i])
		i++;
	j = 0;
	while (--i >= 0)
	{
		nb += my_pow(radix, i) * position_in_base(str[j], base);
		j++;
	}
	return (nb);
}
