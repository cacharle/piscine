/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 07:50:11 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/09 10:20:25 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


static int	is_prime(int nb)
{
	long unsigned int	i;

	if (nb <= 1)
		return (0);
	if (nb <= 3)
		return (1);
	if (nb % 2 == 0 || nb % 3 == 0)
		return (0);
	i = 5;
	while (i * i <= nb)
	{
        if (nb % i == 0 || nb % (i + 2) == 0)
            return (0);
        i += 6;
	}
	return (1);
}

int     ft_find_next_prime(int nb)
{
	while (!is_prime(nb))
		nb++;
	return (nb);
}
