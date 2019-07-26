/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 11:35:43 by exam              #+#    #+#             */
/*   Updated: 2019/07/26 12:32:57 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		count_len(int nbr)
{
	int				counter;
	unsigned int	u_nbr;

	if (nbr == 0)
		return (1);
	counter = 0;
	u_nbr = nbr;
	if (nbr < 0)
	{
		counter++;
		u_nbr = -nbr;
	}
	while (u_nbr > 0)
	{
		u_nbr /= 10;
		counter++;
	}
	return (counter);
}

char	*ft_itoa(int nbr)
{
	char			*str;
	int				len;
	int				is_negative;
	unsigned int	u_nbr;

	len = count_len(nbr);
	if ((str = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	str[len] = '\0';
	is_negative = 0;
	u_nbr = nbr;
	if (nbr < 0)
	{
		is_negative = 1;
		str[0] = '-';
		u_nbr = -nbr;
	}
	len--;
	while (len >= (is_negative ? 1 : 0))
	{
		str[len] = u_nbr % 10 + '0';
		u_nbr /= 10;
		len--;
	}
	return (str);
}
