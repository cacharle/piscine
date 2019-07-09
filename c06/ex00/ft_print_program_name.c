/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 14:53:06 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/09 18:27:49 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	argc = 0;
	while (**argv)
	{
		write(1, *argv, 1);
		(*argv)++;
	}
	write(1, "\n", 1);
	return (0);
}
