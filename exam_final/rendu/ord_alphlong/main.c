/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 14:37:24 by exam              #+#    #+#             */
/*   Updated: 2019/07/26 16:33:22 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "include.h"

#include <stdio.h>
int	main(int argc, char **argv)
{
	char **strs;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	strs = ft_split(argv[1]);
	sort_strs(strs, &strlen_cmp);
	sort_strs(strs, &str_lettercmp);
	print_strs(strs);
	return (0);
}
