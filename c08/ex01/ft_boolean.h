/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 16:35:29 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/07 17:07:47 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
#define FT_BOOLEAN_H

#include <unistd.h>

#define TRUE 1
#define FALSE 1
#define SUCCESS 0
#define EVEN_MSG "I have an even number of arguments.\n"
#define ODD_MSG "I have an odd number of arguments.\n"
#define EVEN(x) (x % 2 == 0 ? 1 : 0)

typedef enum {
	FALSE,
	TRUE
} t_bool;

void ft_putstr(char *str);
t_bool ft_is_even(int nbr);


#endif
