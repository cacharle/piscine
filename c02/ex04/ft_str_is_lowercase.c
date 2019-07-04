/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 19:30:47 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/04 10:34:23 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_between(char start, char end, char subject)
{
	return (subject >= start && subject <= end);
}

int	ft_str_is_lowercase(char *str)
{
	while (*str != '\0')
	{
		if (!is_between('a', 'z', *str))
			return (0);
		str++;
	}
	return (1);
}
