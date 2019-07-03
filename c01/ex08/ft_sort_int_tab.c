/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 18:06:03 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/03 18:14:54 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_sorted(int *tab, int size)
{
	int i;

	i = 0;
	while (i < size - 1)
		if (tab[i] > tab[i + 1])
			return (0);
	return (1);
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	tmp;

	while (!is_sorted(tab, size))
	{
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
			}
			i++;
		}
	}
}
