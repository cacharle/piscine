/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 17:15:32 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/14 11:12:08 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int					ft_strlen(char *str)
{
	int	counter;

	counter = 0;
	while (str[counter])
		counter++;
	return (counter);
}

char				*ft_strdup(char *src)
{
	int		i;
	char	*dup_ptr;

	dup_ptr = (char*)malloc(sizeof(char) * ft_strlen(src));
	if (dup_ptr == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dup_ptr[i] = src[i];
		i++;
	}
	dup_ptr[i] = '\0';
	return (dup_ptr);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	tmp_stock;
	t_stock_str	*strs_stocks;

	if ((strs_stocks = malloc(sizeof(t_stock_str) * (ac + 1))) == NULL)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		tmp_stock.size = ft_strlen(av[i]);
		tmp_stock.str = av[i];
		if ((tmp_stock.copy = ft_strdup(av[i])) == NULL)
			return (NULL);
		strs_stocks[i++] = tmp_stock;
	}
	strs_stocks[ac].str = 0;
	return (strs_stocks);
}
