/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 19:10:32 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/04 10:12:29 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_between(char start, char end, char subject)
{
	printf("--%c %c %c\n", start, end, subject);
	return (subject >= start && subject <= end);
}

int	ft_str_is_alpha(char *str)
{
	while (*str != '\0')
	{
		printf("%c ", *str);
		if (!(is_between('a', 'z', *str) || is_between('A', 'Z', *str)))
			return (0);
		str++;
	}
	return (1);
}
