/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 19:10:32 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/03 19:40:15 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_between(char start, char end, char subject)
{
	return (subject >= start && subject <= end);
}

int	ft_str_is_alpha(char *str)
{
	while (*str != '\0')
		if (!is_between('a', 'z', *str) || !is_between('A', 'Z', *str))
			return (0);
	return (1);
}
