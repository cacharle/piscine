/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 19:33:13 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/03 19:40:56 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_between(char start, char end, char subject)
{
	return (subject >= start && subject <= end);
}

int	ft_str_is_uppercase(char *str)
{
	while (*str != '\0')
		if (!is_between('A', 'Z', *str))
			return (0);
	return (1);
}
