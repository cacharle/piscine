/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 18:06:43 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/11 18:45:01 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#define BUFFER_SIZE 1
#include <stdio.h>

int	write_buffer(char *buf)
{
	int i;

	i = 0;
	while (buf[i])
	{
		write(STDOUT_FILENO, &buf[i], 1);
		/*printf("%d %c\n", buf[i], buf[i]);*/
		if (buf[i] == -1)
			return (1);
		i++;
	}
	return (0);
}

int main(int argc, char **argv)
{
	int		fildes;
	char	buf[BUFFER_SIZE];
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
	while (1)
	{
		if (read(fildes, buf, BUFFER_SIZE) == 0)
			break;
		write_buffer(buf);
	}
	close(fildes);
	return (0);
}
