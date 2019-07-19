/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 09:04:03 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/19 06:59:37 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "include.h"

int		print_tail(char *filename, int tail_size, int argc, int good_counter)
{
	int		fildes;

	if ((fildes = open(filename, O_RDONLY)) < 0)
		return (-1);
	if (argc != 1 && good_counter != 0)
		ft_putstr("\n");
	if (argc > 4)
	{
		ft_putstr("==> ");
		ft_putstr(filename);
		ft_putstr(" <==\n");
	}
	if ((print_file_tail(fildes, tail_size)) < 0)
		return (-1);
	if ((close(fildes)) < 0)
		return (-1);
	return (0);
}

int		print_file_tail(int fildes, int tail_size)
{
	char	*file;
	int		file_size;

	file = NULL;
	file_size = read_file(fildes, &file);
	if (file_size < 0)
		return (-1);
	if (tail_size > file_size)
		tail_size = file_size;
	if (file == NULL)
		return (0);
	if ((write(STDOUT_FILENO, file + file_size - tail_size, tail_size)) < 0)
		return (-1);
	free(file);
	return (0);
}

int		read_file(int fildes, char **file)
{
	char	buf[BUF_SIZE];
	int		file_size;
	int		read_size;

	file_size = 0;
	while ((read_size = read(fildes, buf, BUF_SIZE)))
	{
		if (read_size < 0)
			return (-1);
		*file = ft_memcat(*file, buf, file_size, read_size);
		file_size += read_size;
	}
	return (file_size);
}

char	*ft_memcat(char *file, char buf[BUF_SIZE], int file_size,
					int read_size)
{
	int		i;
	char	*file_clone;

	if ((file_clone = malloc(sizeof(char) * (file_size + 1))) == NULL)
		return (NULL);
	i = -1;
	while (++i < file_size)
		file_clone[i] = file[i];
	free(file);
	if ((file = malloc(sizeof(char) * (file_size + read_size + 1))) == NULL)
		return (NULL);
	i = 0;
	while (i < file_size)
	{
		file[i] = file_clone[i];
		i++;
	}
	free(file_clone);
	while (i < file_size + read_size)
	{
		file[i] = buf[i - file_size];
		i++;
	}
	return (file);
}
