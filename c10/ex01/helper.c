/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 10:14:16 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/16 13:42:08 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <libgen.h>
#include "include.h"

void	ft_putstr_err(char *str)
{
	while (*str)
		write(STDERR_FILENO, str++, 1);
}

void	handle_error(char *program_name, char *arg)
{
	char *error_msg;

	ft_putstr_err(basename(program_name));
	ft_putstr_err(": ");
	ft_putstr_err(arg);
	ft_putstr_err(": ");
	error_msg = strerror(errno);
	ft_putstr_err(error_msg);
	ft_putstr_err("\n");
}
