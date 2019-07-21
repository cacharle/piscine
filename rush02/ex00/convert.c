/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiacono <yiacono@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 11:14:59 by yiacono           #+#    #+#             */
/*   Updated: 2019/07/21 15:03:02 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"
#include <unistd.h>

static int		check_arg(t_max_nbr nb, t_dict dict)
{
	if (nb < 0)
		return (-1);
	if (nb == 0)
	{
		while (dict->key > 0)
			dict++;
		ft_putstr(dict->value);
		return (0);
	}
	if ((nb / dict->key) >= 1000)
		return (-1);
	return (0);
}

static void		effective_convert(t_max_nbr nb, t_dict dict)
{
	t_max_nbr	div_result;

	while (nb > 0)
	{
		div_result = nb / dict->key;
		if (div_result)
		{
			if (div_result == 1 && dict->key >= 100)
			{
				effective_convert(div_result, dict);
				ft_putstr(" ");
			}
			else if (div_result > 1)
			{
				effective_convert(div_result, dict);
				ft_putstr(" ");
			}
			ft_putstr(dict->value);
			nb = nb % dict->key;
			if (nb)
				ft_putstr(" ");
		}
		dict++;
	}
}

int				convert(t_max_nbr nb, t_dict dict)
{
	if (check_arg(nb, dict) < 0)
		return (-1);
	effective_convert(nb, dict);
	ft_putstr("\n");
	return (0);
}
