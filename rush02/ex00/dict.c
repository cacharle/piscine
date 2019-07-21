/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 18:44:04 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/21 15:01:26 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "include.h"

static int	is_sorted(t_dict dict)
{
	int i;

	i = 0;
	while (dict[i + 1].key != -1)
	{
		if (dict[i].key < dict[i + 1].key)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void		sort_dict(t_dict dict)
{
	int		i;
	t_entry	tmp;

	while (!is_sorted(dict))
	{
		i = 0;
		while (dict[i + 1].key != -1)
		{
			if (dict[i].key < dict[i + 1].key)
			{
				tmp = dict[i];
				dict[i] = dict[i + 1];
				dict[i + 1] = tmp;
			}
			i++;
		}
	}
}

int			as_uniq_keys(t_dict dict)
{
	int	i;

	while (dict->value != NULL)
	{
		i = 1;
		while (dict[i].value != NULL)
		{
			if (dict->key == dict[i].key)
				return (FALSE);
			i++;
		}
		dict++;
	}
	return (TRUE);
}

int			required_values(t_dict dict)
{
	int			i;
	t_max_nbr	key;
	int			keys_checked;

	i = 0;
	keys_checked = 0;
	while (dict[i].key != -1)
	{
		key = dict[i].key;
		if (key == 0 || key == 1 || key == 2 || key == 3 || key == 4 || key == 5
			|| key == 6 || key == 7 || key == 8 || key == 9 || key == 10
			|| key == 11 || key == 12 || key == 13 || key == 14 || key == 15
			|| key == 16 || key == 17 || key == 18 || key == 19 || key == 20
			|| key == 30 || key == 40 || key == 50 || key == 60 || key == 70
			|| key == 80 || key == 90 || key == 100 || key == 1000
			|| key == 1000000 || key == 1000000000)
			keys_checked++;
		i++;
	}
	return (keys_checked == REQUIRED_SIZE);
}

/*
** destroy dict, by freeing each value and the dict itself
*/

void		destroy_dict(t_dict dict, int size)
{
	int i;

	if (dict == NULL)
		return ;
	i = 0;
	if (size == -1)
		while (dict[i].key != -1)
		{
			free(dict[i].value);
			i++;
		}
	else
		while (--size > 0)
			free(dict[size].value);
	free(dict);
}
