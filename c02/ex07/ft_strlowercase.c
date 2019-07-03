/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowercase.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 19:53:41 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/03 19:54:46 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_between(char start, char end, char subject)
{
	return (subject >= start && subject <= end);
}

char	*ft_strlowcase(char *str)
{
	while (*str != '\0')
		if (is_between('A', 'Z', *str)
			*str = *str - 'A' + 'a';
	return (str);
}
