/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 19:48:22 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/03 19:51:38 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_between(char start, char end, char subject)
{
	return (subject >= start && subject <= end);
}

char *ft_strupcase(char *str)
{
	while (*str != '\0')
		if (is_between('a', 'z', *str)
			*str = *str - 'a' + 'A';
	return (str);
}
