/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agassin <agassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 10:47:14 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/21 14:44:22 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "include.h"

/*
** Open the dictionnary file, pass it to `parse_dict`
** return the dict, NULL if an error occurs
*/

t_dict	parse_dict_file(char *filename)
{
	char	*file;
	int		fildes;
	int		file_size;
	t_dict	dict;

	if ((fildes = open(filename, O_RDONLY)) < 0)
		return (NULL);
	file = NULL;
	if ((file_size = read_file(fildes, &file)) < 0)
		return (NULL);
	if ((dict = parse_dict(file, file_size)) == NULL)
	{
		destroy_dict(dict, -1);
		free(file);
		return (NULL);
	}
	free(file);
	if (close(fildes) < 0)
		return (NULL);
	return (dict);
}

/*
** Parse the file and return a dictionary where the keys are
** the numbers and the values the string attached to it
*/

t_dict	parse_dict(char *file, int file_size)
{
	int		i;
	int		j;
	t_dict	dict;

	dict = (t_dict)malloc(sizeof(t_entry) * (count_lines(file) + 1));
	if (dict == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < file_size)
	{
		while (file[i] && file[i] == '\n')
			i++;
		if (file[i] && (set_entry(&file[i], &dict[j++])) == -1)
		{
			destroy_dict(dict, j - 1);
			return (NULL);
		}
		while (file[i] && file[i] != '\n')
			i++;
	}
	dict[j].key = -1;
	dict[j].value = NULL;
	return (dict);
}

/*
** Set the key and value of an entry based on the given line
** return -1 if an error occurs
*/

int		set_entry(char *line, t_entry *entry)
{
	int		i;
	char	*tmp;

	i = 0;
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	if (i == 0)
		return (-1);
	tmp = ft_strndup(line, i);
	entry->key = strict_atoi(tmp);
	free(tmp);
	while (line[i] == ' ')
		i++;
	if (line[i] != ':')
		return (-1);
	i++;
	while (line[i] == ' ')
		i++;
	entry->value = filtered_value(&line[i]);
	if (entry->value == NULL)
		return (-1);
	return (0);
}

/*
** Duplicate the line and compress spaces until there is only one left
*/

char	*filtered_value(char *str)
{
	int		i;
	int		j;
	char	*value;

	i = 0;
	while (str[i] != '\n')
		i++;
	if (i == 0)
		return (NULL);
	if ((value = (char*)malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
	{
		value[j++] = str[i++];
		while (str[i] && str[i] == ' ')
		{
			if (str[i + 1] && str[i + 1] != ' ')
				break ;
			i++;
		}
	}
	value[i] = '\0';
	return (value);
}

/*
** count the number of line in the file
** without counting empty lines
*/

int		count_lines(char *file)
{
	int	counter;

	counter = 0;
	while (*file)
	{
		if (*file == '\n')
		{
			counter++;
			while (*file == '\n')
				file++;
		}
		file++;
	}
	return (counter);
}
