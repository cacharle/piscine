/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 16:48:21 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/06 17:14:26 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_iterative_factorial(int nb)
{
	int	acc;
	int	i;

	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	acc = 1;
	while (nb > 0)
		acc *= nb--;
	return (acc);
}
