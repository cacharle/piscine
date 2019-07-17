/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 21:51:06 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/16 21:54:24 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_sorted(char **tab, int(*cmp)(char *, char *))
{
	int i;

	i = 1;
	while (tab[i] != NULL)
	{
		if ((*cmp)(tab[i], tab[i +1]) > 0)
			return (0);
		i++;
	}
	return (1);
}

void ft_advanced_sort_string_tab(char **tab, int(*cmp)(char *, char *))
{
	int		i;
	char	*tmp;

	while (!is_sorted(tab))
	{
		i = 1;
		while (tab[i] != NULL)
		{
			if ((*cmp)(tab[i], tab[i +1]) > 0)
			{
				tmp = argv[i];
				argv[i] = argv[i + 1];
				argv[i + 1] = tmp;
			}
			i++;
		}
	}
}
