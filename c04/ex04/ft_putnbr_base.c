/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 07:47:44 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/06 08:37:59 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_base(char *base)
{
	int	i;

	if (!*base)
		return (0);
	while (*base)
	{
		if (*base == '-' || *base == '+')
			return (0);
		i = 0;
		while (base[i])
		{
			if (base[i] == *base)
				return (0);
			i++;
		}
	}
	return (1);
}

int		my_strlen(char *str)
{
	int	counter;

	counter = 0;
	while (*str)
	{
		counter++;
		str++;
	}
	return (counter);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	radix;
	int	i;
	int	nb;
	int rev_digits[1024];

	if (!check_base(base))
		return;
	radix = my_strlen(base);
	nb = 0;
	i = 0;
	while (nb > 0)
	{
		rev_digits[i] = base[nb % radix];
		nb /= radix;
		i++;
	}
	while (i > 0)
	{
		i--;
		write(1, rev_digits  + i, 1);
	}
}
