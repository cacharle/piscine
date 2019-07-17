/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 15:26:12 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/17 14:07:21 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_H
# define INCLUDE_H

# define BUF_SIZE 32000


/*
** file.c
*/

int		print_tail(char *filename, int tail_size);
int		read_file(int fildes, char **file);
char	*char_realloc(char *ptr, int size);

/*
** helper.c
*/

int		ft_strlen(char *str);
int		ft_atoi(char *str);
int		pow10(int exponent);

/*
** handle_error.c
*/

void	handle_error(char *program_name, char *arg_name);
void	ft_putstr_err(char *str);

#endif
