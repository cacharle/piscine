/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 15:43:34 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/06 07:12:28 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	my_strlen(char *str)
{
	int counter;

	counter = 0;
	while (*str != '\0')
	{
		counter++;
		str++;
	}
	return (counter);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	len_src;
	unsigned int	len_dest;

	len_src = my_strlen(src);
	len_dest = my_strlen(dest);
	if (!len_src)
		return (len_dest);
	i = len_dest - 1;
	while (i < size - len_dest - 1 && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (len_src + len_dest);
}
