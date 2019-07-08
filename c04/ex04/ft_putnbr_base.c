/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 07:47:44 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/07 18:13:58 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+')
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

int		my_strlen(char *str)
{
	int	counter;

	counter = 0;
	while (str[counter])
		counter++;
	return (counter);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int				radix;
	int				i;
	unsigned int	nbu;
	char			rev_digits[1024];

	if (!check_base(base))
		return ;
	radix = my_strlen(base);
	nbu = nbr;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbu = -nbr;
	}
	i = 0;
	while (nbu > 0)
	{
		rev_digits[i] = base[nbu % radix];
		nbu /= radix;
		i++;
	}
	while (i-- > 0)
		write(1, rev_digits + i, 1);
}
