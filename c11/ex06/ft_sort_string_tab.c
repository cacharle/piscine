/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 21:48:20 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/17 16:43:27 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1 && *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int		is_sorted(char **argv)
{
	int i;

	i = 1;
	while (argv[i + 1] != NULL)
	{
		if (ft_strcmp(argv[i], argv[i + 1]) > 0)
			return (0);
		i++;
	}
	return (1);
}

void ft_sort_string_tab(char **tab)
{
	int		i;
	char	*tmp;

	while (!is_sorted(argv))
	{
		i = 1;
		while (tab[i + 1] != NULL)
		{
			if (ft_strcmp(tab[i], tab[i + 1]) > 0)
			{
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
			}
			i++;
		}
	}
}
