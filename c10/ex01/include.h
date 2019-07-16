/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 16:49:28 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/16 10:23:45 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_H
# define INCLUDE_H

# define BUF_SIZE 64

/*
** io.c
*/

int		read_in_buf(int fildes, char buf[BUF_SIZE]);
int		write_buf(char buf[BUF_SIZE], int size);
int		read_write_fildes(int fildes);
int		print_file(char *filename);

/*
** helper.c
*/

void	handle_error(char *program_name, char *arg);
void	ft_putstr_err(char *str);

#endif
