/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 21:39:43 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/19 07:37:39 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	is_sort_asc(int *tab, int length, int (*f)(int, int))
{
	int i;

	i = 0;
	while (i < length - 1)
	{
		if ((*f)(tab[i], tab[i + 1]) > 0)
			return (0);
		i++;
	}
	return (1);
}

static int	is_sort_dsc(int *tab, int length, int (*f)(int, int))
{
	int i;

	i = 0;
	while (i < length - 1)
	{
		if ((*f)(tab[i], tab[i + 1]) < 0)
			return (0);
		i++;
	}
	return (1);
}

int			ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	return (is_sort_dsc(tab, length, f) || is_sort_asc(tab, length, f));
}
