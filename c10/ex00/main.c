/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 18:06:43 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/15 13:45:33 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#define BUFFER_SIZE 1
#include <stdio.h>

void	read_write_file(int	fildes)
{
	int i;
	int	writing;
	char	buf[BUFFER_SIZE];

	writing = 1;
	while (writing)
	{
		if (read(fildes, buf, BUFFER_SIZE) == 0)
			break;
		i = 0;
		while (buf[i])
		{
			write(STDOUT_FILENO, &buf[i], 1);
			if (buf[i] == -1)
				writing = 0;
			i++;
		}
	}
}

int main(int argc, char **argv)
{
	int		fildes;
	int		reading;

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
	read_write_file(fildes);
	close(fildes);
	return (0);
}
