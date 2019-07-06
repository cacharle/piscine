/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 08:07:17 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/06 12:47:25 by cacharle         ###   ########.fr       */
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

int	position_in_base(char digit, char *base)
{
	int	i;

	i = 0;
	while (base[i] != digit)
		i++;
	return (i);
}

int ft_atoi_base(char *str, char *base)
{
	int	radix;
	int	i;
	int	j;
	int	nb;

	nb = 0;
	radix = 0;
	while (base[++radix]);
	i = 0;
	while (str[++i]);
	printf("%s base %d (%s)\n", str, radix, base);
	j = 0;
	while (--i >= 0)
	{
		printf("%c: %d * (%d^%d) = %d\n", str[i], position_in_base(str[i], base), radix, i,  my_pow(radix, i) * position_in_base(str[j], base));
		nb += my_pow(radix, i) * position_in_base(str[j], base);
		j++;
	}
	return (nb);
}
