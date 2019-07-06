/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 07:31:38 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/06 10:23:20 by cacharle         ###   ########.fr       */
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
	int	j;

	while (*str == ' ' || *str == '\t' || *str == '\n'
		   || *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	is_negative = 0;
	/*printf("> %s\n", str);*/
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			is_negative = !is_negative;
		str++;
	}
	/*printf("> %s\n", str);*/
	nb = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	j = 0;
	while (str[j] >= '0' && str[j] <= '9')
	{
		/*printf("%d i, %d nb\n", i, nb);*/
		i--;
		nb += pow10(i) * (str[j] - '0');
		j++;
	}
	if (is_negative)
		nb = -nb;
	return (nb);
}
