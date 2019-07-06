/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 07:47:44 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/06 11:12:25 by cacharle         ###   ########.fr       */
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
	int		radix;
	int		i;
	int		nb;
	char	rev_digits[1024];

	if (!check_base(base))
		return;
	radix = my_strlen(base);
	i = 0;
	/*printf("\n%d base %d (%s)\n", nbr, radix,  base);*/
	while (nbr > 0)
	{
		/*printf("%d %d %c\n", nbr, nbr % radix, base[nbr % radix]);*/
		rev_digits[i] = base[nbr % radix];
		nbr /= radix;
		i++;
	}
	/*for (int k = 0; k < 10; k++)*/
		/*printf("%d ", rev_digits[k]);*/
	while (i > 0)
	{
		i--;
		write(1, rev_digits  + i, 1);
	}
}
