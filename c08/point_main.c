/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 14:50:27 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/11 14:51:48 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex03/ft_point.h"

void	set_point(t_point *point)
{
	point->x = 42;
	point->y = 21;
}

int		main(void)
{
	t_point	point;

	set_point(&point);
	return (0);
}
