/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 15:20:54 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/05 16:46:57 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define MY_NULL 0x0

int	ft_strlen(char *str)
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

char *ft_strstr(char *str, char *to_find)
{
	int	i;

	if (!ft_strlen(to_find))
		return str;
	while (*str)
	{
		i = 0;
		while (to_find[i] && str[i])
		{
			if (to_find[i] != str[i])
				break;
			i++;
		}
		if (i == ft_strlen(to_find))
			return (str);
		str++;
	}
	return (MY_NULL);
}
