/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 18:06:43 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/19 06:33:07 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#define BUFFER_SIZE 1024

int		read_write_file(int fildes)
{
	char	buf[BUFFER_SIZE];
	int		read_size;

	while ((read_size = read(fildes, buf, BUFFER_SIZE)) != 0)
	{
		if (read_size < 0)
			return (-1);
		write(STDOUT_FILENO, buf, read_size);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	int		fildes;

	if (argc == 1)
	{
		write(STDERR_FILENO, "File name missing.\n", 20);
		return (1);
	}
	else if (argc > 2)
	{
		write(STDERR_FILENO, "Too many arguments.\n", 21);
		return (1);
	}
	if ((fildes = open(argv[1], O_RDONLY)) < 0)
	{
		write(STDERR_FILENO, "Cannot read file.\n", 18);
		return (1);
	}
	if ((read_write_file(fildes)) < 0)
	{
		write(STDERR_FILENO, "Cannot read file.\n", 18);
		return (1);
	}
	close(fildes);
	return (0);
}
