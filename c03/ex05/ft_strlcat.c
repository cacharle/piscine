/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 15:43:34 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/07 11:08:08 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	my_strlen(char *str)
{
	int counter;

	counter = 0;
	while (str[counter])
		counter++;
	return (counter);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	dest_len;
	unsigned int	src_len;

	dest_len = my_strlen(dest);
	src_len = my_strlen(src);
	if (size == 0)
		return (src_len);
	i = dest_len;
	while (i < size - 1)
	{
		dest[i] = src[i - dest_len];
		i++;
	}
	if (dest[size - 1] != '\0')
		return (src_len + size);
	dest[size - 1] = '\0';
	return (dest_len + src_len);
}
