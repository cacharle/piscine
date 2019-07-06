/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 08:07:17 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/06 08:30:16 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int ft_atoi_base(char *str, char *base)
{
	int	radix;
	int	i;
	int	j;
	int	nb;

	radix = 0;
	while (base[radix])
		radix++;
	i = 0;
	while (str[i])
		i++;
	j = 0;
	while (i > 0)
	{
		nb += my_pow(radix, j);
		nb %= radix;
		i--;
		j++;
	}
	return nb;
}
