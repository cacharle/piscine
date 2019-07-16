/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 19:05:32 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/16 10:52:03 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "include.h"

int    read_in_buf(int fildes, char buf[BUF_SIZE])
{
	return (read(fildes, buf, BUF_SIZE - 1));
}

int    write_buf(char buf[BUF_SIZE], int size)
{
	return (write(1, buf, size));
}

int		read_write_fildes(int fildes)
{
	int		size;
	char	buf[BUF_SIZE];

	size = BUF_SIZE - 1;
	while (size == BUF_SIZE - 1 || fildes == STDOUT_FILENO )
	{
		if ((size = read_in_buf(fildes, buf)) == -1)
			return (-1);
		if (write_buf(buf, size) == -1)
			return (-1);
	}
	return (0);
}

int	print_file(char *filename)
{
	int	fildes;

	if (filename[0] == '-')
		fildes = STDIN_FILENO;
	else if ((fildes = open(filename, O_RDONLY)) < 0)
		return (-1);
	if (read_write_fildes(fildes) == -1)
		return (-1);
	if (close(fildes) == -1)
		return (-1);
	return (0);
}
