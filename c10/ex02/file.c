/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 09:04:03 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/17 15:49:06 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "include.h"

int	print_tail(char *filename, int tail_size)
{
	char	*file;
	int		fildes;
	int		file_len;

	if ((fildes = open(filename, O_RDONLY)) == -1)
	{
		close(fildes);
		return (-1);
	}
	file = NULL;
	if ((file_len = read_file(fildes, &file)) == -1)
		return (-1);
	/*printf("%s \n %d", file + 29000, ft_strlen(file));*/
	/*for (int i = 0; i < 100; i++)*/
		/*printf("%c", file[i]);*/
	if (write(STDOUT_FILENO, &file[file_len - tail_size], tail_size) == -1)
		return (-1);
	free(file);
	if (close(fildes) == -1)
		return (-1);
	return (0);
}

int	read_file(int fildes, char **file)
{
	size_t	size;
	size_t	read_size;
	int	file_len;

	/**file = malloc(sizeof(char) * 100);*/
	file_len = 0;
	size = BUF_SIZE;
	read_size = BUF_SIZE;
	while (!(read_size < BUF_SIZE))
	{
		/*printf("size %d\n", size);*/
		*file = char_realloc(*file, size);
		read_size = read(fildes, *file, BUF_SIZE);
		/*printf("%s", *file);*/
		if (read_size < BUF_SIZE)
			file_len += ft_strlen(*file + BUF_SIZE - read_size);
		else
			file_len += BUF_SIZE;
		size += BUF_SIZE;
		/*size *= 2;*/
	}
	printf("file_len %d\n", file_len);
	return (file_len);
}

char	*char_realloc(char *ptr, int size)
{
	int		i;
	char	*reallocated_ptr;

	reallocated_ptr = (char*)malloc(sizeof(char) * size);
	i = 0;
	while (i < size - BUF_SIZE)
	{
	reallocated_ptr[i] = ptr[i];
	i++;
	}
	reallocated_ptr[i] = '\0';
	free(ptr);
	return (reallocated_ptr);
}
