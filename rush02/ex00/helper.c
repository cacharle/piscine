/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <cacharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 07:25:21 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/21 08:23:41 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "include.h"

/*
** Read an already openned file in `file`
** return the file_size (-1 if a error occurs)
*/

int		read_file(int fildes, char **file_ptr)
{
	char	buf[BUF_SIZE];
	int		file_size;
	int		read_size;

	file_size = 0;
	while ((read_size = read(fildes, buf, BUF_SIZE)))
	{
		if (read_size < 0)
			return (-1);
		*file_ptr = ft_memcat(*file_ptr, buf, file_size, read_size);
		file_size += read_size;
	}
	return (file_size);
}

/*
** Concatenate buf[buf_size] into file[file_size]
** Create a copy of the file, free file,
** reallocate it with sufficient memory for the concatenation
** copy each character of file_copy then buf into file
** free file_copy
*/

char	*ft_memcat(char *file, char buf[BUF_SIZE], int file_size,
					int buf_size)
{
	int		i;
	char	*file_copy;

	if ((file_copy = malloc(sizeof(char) * (file_size + 1))) == NULL)
		return (NULL);
	i = -1;
	while (++i < file_size)
		file_copy[i] = file[i];
	free(file);
	if ((file = malloc(sizeof(char) * (file_size + buf_size + 1))) == NULL)
		return (NULL);
	i = 0;
	while (i < file_size)
	{
		file[i] = file_copy[i];
		i++;
	}
	free(file_copy);
	while (i < file_size + buf_size)
	{
		file[i] = buf[i - file_size];
		i++;
	}
	return (file);
}

char	*ft_strndup(char *src, int n)
{
	int		i;
	char	*dup_ptr;

	dup_ptr = (char*)malloc(sizeof(char) * (n + 1));
	if (dup_ptr == NULL)
		return (NULL);
	i = 0;
	while (src[i] && i < n)
	{
		dup_ptr[i] = src[i];
		i++;
	}
	dup_ptr[i] = '\0';
	return (dup_ptr);
}

/*
** Print a string char by char on the standard output
*/

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}
