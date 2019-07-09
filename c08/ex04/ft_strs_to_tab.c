/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 17:15:32 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/08 17:10:21 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

struct s_stock_str *ft_strs_to_tab(int ac, char **av)
{
	int			i;
	char		*copy;
	t_stock_str	tmp_stock;
	t_stock_str	*strs_stocks

	strs_stocks	= malloc(sizeof(t_stock_str) * ac);
	while (ac-- > 0)
	{
		i = 0
		while (av[ac][i])
			i++;
		tmp_stock = malloc(sizeof(t_stock_str));
		tmp_stock->size = i;
		tmp_stock->str = av[ac];
		copy = malloc(sizeof(char) * i);
		i = -1;
		while (av[ac][i++])
			copy[i] = av[ac][i];
		tmp_stock->copy = copy;
		strs_stocks[ac] = tmp_stock;
	}
	return (strs_stocks);
}
