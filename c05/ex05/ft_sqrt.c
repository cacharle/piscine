/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 20:06:48 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/09 06:38:18 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	bin_search_sqrt(long unsigned int nb, unsigned int low, unsigned int up)
{
	long unsigned int	mid;

	mid = low + ((up - low) / 2);
	if (mid * mid == nb)
		return (mid);
	if (low > up)
		return (0);
	if (mid * mid < nb)
		return (bin_search_sqrt(nb, mid + 1, up));
	else
		return (bin_search_sqrt(nb, low, mid - 1));
}

int	ft_sqrt(int nb)
{
	if (nb < 0)
		return (0);
	return (bin_search_sqrt(nb, 0, nb));
}
