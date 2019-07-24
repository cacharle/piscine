/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 11:01:32 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/24 14:50:39 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "include.h"

int	main(int argc, char **argv)
{
	int					i;
	t_parsed_terrain	*pterrain;

	pterrain = NULL;
	if (argc == 1)
	{
		parse_stdin_print();
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		parse_file_print(argv[i]);
		if (i != argc - 1)
			ft_putchar('\n');
		i++;
	}
	return (0);
}
