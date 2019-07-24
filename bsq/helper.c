/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 15:19:53 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/24 17:59:52 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "include.h"

/*
 ** Dynamic allocation of buffer
*/

char	*read_file(int fildes)
{
	char	*buf;
	char	*file;
	int		file_size;
	int		read_size;
	int		buf_size;

	buf_size = INIT_BUF_SIZE;
	file_size = 0;
	file = NULL;
	if ((buf = malloc(sizeof(char) * buf_size)) == NULL)
		return (NULL);
	while ((read_size = read(fildes, buf, buf_size)))
	{
		if (read_size < 0)
			return (NULL);
		if ((file = ft_memcat(file, buf, file_size, read_size)) == NULL)
			return (NULL);
		file_size += read_size;
		buf_size *= GROWTH_FACTOR;
		if ((buf = realloc_buf(buf, buf_size)) == NULL)
			return (NULL);
	}
	free(buf);
	return (file);
}

/*
 ** Reallocate a bigger  memory space for file to write what in the buffer
*/

char	*ft_memcat(char *file, char *buf, int file_size,
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
	file[i] = '\0';
	return (file);
}

/*
 ** Reallocate a new buffer and free the old one
*/

char	*realloc_buf(char *buf, int buf_size)
{
	free(buf);
	if ((buf = (char*)malloc(sizeof(char) * buf_size)) == NULL)
		return (NULL);
	return (buf);
}

/*
 ** Return the n number of a string and return it as an int
*/

int		ft_natoi(char *str, unsigned int n)
{
	int				nb;
	unsigned int	i;

	nb = 0;
	i = 0;
	while (str[i] && i < n)
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		i++;
	}
	if (i == 0)
		return (-1);
	i = 0;
	while (str[i] && i < n)
	{
		nb *= 10;
		nb += str[i++] - '0';
	}
	if (nb == 0)
		return (-1);
	return (nb);
}

/*
 ** Print one character in the standard output
*/

void	ft_putchar(char c)
{
	write(STDOUT_FILENO, &c, 1);
}
