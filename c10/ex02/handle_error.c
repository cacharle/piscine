/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 13:04:59 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/17 13:05:34 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libgen.h>
#include <string.h>
#include <errno.h>
#include "include.h"

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

void	ft_putstr_err(char *str)
{
	while (*str)
		write(STDERR_FILENO, str++, 1);
}
