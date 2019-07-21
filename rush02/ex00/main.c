/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiacono <yiacono@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 07:25:21 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/21 15:02:43 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "include.h"

int	main(int argc, char **argv)
{
	t_dict		dict;
	t_max_nbr	nb;

	if (print_error_if(argc > 3 || argc == 1, NULL))
		return (1);
	if (argc == 2)
	{
		dict = parse_dict_file("numbers.dict");
		nb = strict_atoi(argv[1]);
	}
	if (argc == 3)
	{
		dict = parse_dict_file(argv[1]);
		nb = strict_atoi(argv[2]);
	}
	if (print_error_if(nb == -1, dict))
		return (1);
	if (print_dict_error_if(dict == NULL || !required_values(dict)
		|| !as_uniq_keys(dict), dict))
		return (1);
	sort_dict(dict);
	if (print_error_if(convert(nb, dict), dict))
		return (1);
	destroy_dict(dict, -1);
	return (0);
}
