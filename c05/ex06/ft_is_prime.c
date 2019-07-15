/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 20:17:59 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/12 07:43:36 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	long unsigned int	i;
	long unsigned int	nbu;

	if (nb <= 1)
		return (0);
	if (nb <= 3)
		return (1);
	if (nb % 2 == 0 || nb % 3 == 0)
		return (0);
	i = 1;
	nbu = nb;
	while (i * i <= nbu) // ne fonctionne pas de 7 a 41
	{
		if (nbu % (i * 6 - 1) == 0)
			return (0);
		if (nbu % (i * 6 + 1) == 0)
			return (0);
		i += 1;
	}
	return (1);
}
