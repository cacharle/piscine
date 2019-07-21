/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiacono <yiacono@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 10:55:27 by agassin           #+#    #+#             */
/*   Updated: 2019/07/21 14:17:53 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

/*
** similar to atoi but doesn't allow anything before or after ('-' included)
** return the number or -1 in case of error
*/

t_max_nbr	strict_atoi(char *str)
{
	t_max_nbr	nb;
	int			i;

	nb = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		i++;
	}
	if (i == 0)
		return (-1);
	i = 0;
	while (str[i])
	{
		nb *= 10;
		nb += str[i++] - '0';
	}
	return (nb);
}

int			print_error_if(int status, t_dict dict)
{
	if (status)
	{
		ft_putstr("Error\n");
		destroy_dict(dict, -1);
	}
	return (status);
}

int			print_dict_error_if(int status, t_dict dict)
{
	if (status)
	{
		ft_putstr("Dict Error\n");
		destroy_dict(dict, -1);
	}
	return (status);
}
