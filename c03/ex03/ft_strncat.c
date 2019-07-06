/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 13:02:04 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/05 15:33:07 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	char			*dest_end;

	i = 0;
	while (dest[i] != '\0')
		i++;
	dest_end = dest + i;
	i = 0;
	while (i < nb && src[i] != '\0')
	{
		dest_end[i] = src[i];
		i++;
	}
	return (dest);
}
