/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 10:04:32 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/05 10:04:38 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	char *head;

	head = str;
	while (*str != '\0')
	{
		if (*str >= 'A' && *str <= 'Z')
			*str = *str - 'A' + 'a';
		str++;
	}
	return (head);
}
