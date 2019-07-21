/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 15:19:53 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/19 15:19:56 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "include.h"

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
