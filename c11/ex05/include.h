/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 07:38:10 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/17 08:15:39 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_H
# define INCLUDE_H

/*
** operators.c
*/

int		add(int x, int y);
int		subtract(int x, int y);
int		multiply(int x, int y);
int		divide(int x, int y);
int		modulo(int x, int y);

/*
** parse.c
*/

int	parse(int argc, char **argv);
//int	make_operation(int x, int y, int (*operator)(int, int))

/*
** helper.c
*/

void	ft_putchar(char c);
void	ft_putnbr(int nb);
int		pow10(int exponent);
int		ft_atoi(char *str);

#endif
