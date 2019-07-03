/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 17:54:22 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/03 18:17:03 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	div_tmp;
	int	mod_tmp;

	div_tmp = *a / *b;
	mod_tmp = *a % *b;
	*a = div_tmp;
	*b = mod_tmp;
}
