/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 19:26:04 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/04 10:31:44 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_between(char start, char end, char subject)
{
	return (subject >= start && subject <= end);
}

int	ft_str_is_numeric(char *str)
{
	while (*str != '\0')
	{
		if (!is_between('0', '9', *str))
			return (0);
		str++;
	}
	return (1);
}
