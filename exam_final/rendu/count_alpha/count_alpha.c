/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_alpha.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 13:36:33 by exam              #+#    #+#             */
/*   Updated: 2019/07/26 14:30:23 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

typedef struct	s_counter
{
	char	letter;
	int		count;
}				t_counter;

int		in_counters(t_counter *counters, char c)
{
	int	i;

	i = 0;
	while (counters[i].letter)
	{
		if (c == counters[i].letter)
			return (1);
		i++;
	}
	return (0);
}

void	str_tolow(char *str)
{
	while (*str)
	{
		if (*str >= 'A' && *str <= 'Z')
			*str += 'a' - 'A';
		str++;
	}
}

int		count_char(char c, char *str)
{
	int	counter;

	counter = 0;
	while (*str)
	{
		if (c == *str)
			counter++;
		str++;
	}
	return (counter);
}

void print_counters(t_counter *counters, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (counters[i].count != 0)
		{
			printf("%d%c", counters[i].count, counters[i].letter);
			if (i != size - 1)
				printf(", ");
		}
		i++;
	}
}

int		main(int argc, char **argv)
{
	t_counter	counters[26];
	int			i;
	int			j;

	if (argc == 2)
	{
		i = 0;
		j = 0;
		while (i < 26)
		{
			counters[i].letter = '\0';
			counters[i].count = 0;
			i++;
		}
		str_tolow(argv[1]);
		i = 0;
		while (argv[1][i])
		{
			if (argv[1][i] >= 'a' && argv[1][i] <= 'z' && !in_counters(counters, argv[1][i]))
			{
				counters[j].letter = argv[1][i];
				counters[j].count = count_char(argv[1][i], argv[1]);
				j++;
			}
			i++;
		}
		print_counters(counters, j);
	}
	printf("\n");
	return (0);
}
