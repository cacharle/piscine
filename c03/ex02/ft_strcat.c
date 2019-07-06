/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 11:52:56 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/05 12:58:36 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *ft_strcat(char *dest, char *src)
{
	char *dest_head;

	dest_head = dest;
	while (*dest)
		dest++;
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
		*dest = *src;
	return dest_head;
}
