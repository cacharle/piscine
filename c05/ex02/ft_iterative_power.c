/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 17:20:15 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/08 12:06:24 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int acc;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	acc = 1;
	while (power > 0)
	{
		acc *= nb;
		power--;
	}
	return (acc);
}
