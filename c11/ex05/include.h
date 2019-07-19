/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 07:38:10 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/18 10:40:10 by cacharle         ###   ########.fr       */
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

int		parse(int argc, char **argv);
int		check_floating_point_error(int operator_index, int y);

/*
** helper.c
*/

void	ft_putchar(char c);
void	ft_putnbr(int nb);
int		pow10(int exponent);
int		ft_atoi(char *str);

#endif
