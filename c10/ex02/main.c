/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 14:51:03 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/17 15:43:59 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h> // remove this
#include "include.h"

int		main(int argc, char **argv)
{
	size_t last_size;
	int i;
	int status;

	status = 0;
	last_size = ft_atoi(argv[2]);
	i = 3;
	while (i < argc)
	{
		if (print_tail(argv[i], last_size) == -1)
		{
			handle_error(argv[0], argv[i]);
			return (1);
		}
		i++;
	}
	return (status);
}
