/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:58:03 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/09 09:40:49 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		count_segment(char *str, char *charset)
{
	int	counter;
	int	i;

	counter = 0;
	while (*str)
	{
		i = 0;
		while (charset[i])
			if (str++ == charset[i++])
			   counter++;
		str++;
	}
	return (counter);
}

int		strlen_until_sep(char *str, char *charset)
{

}

char **ft_split(char *str, char *charset)
{
	char **strs;

	strs = (char**)malloc(sizeof(char*) * count_segment(str, charset));
	printf("%d\n", count_segment(str, charset));
	/*while (*str)*/
	/*{*/

		/*str++;*/
	/*}*/
	return (strs);
}
