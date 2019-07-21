/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 18:06:43 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/20 17:26:47 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#define BUF_SIZE 64

int		main(int argc, char **argv)
{
	int		fildes;
	int		read_size;
	char	buf[BUF_SIZE + 1];

	if (argc < 2)
	{
		write(STDERR_FILENO, "File name missing.\n", 19);
		return (1);
	}
	if (argc > 2)
	{
		write(STDERR_FILENO, "Too many arguments.\n", 20);
		return (1);
	}
	if ((fildes = open(argv[1], O_RDONLY)) == -1)
	{
		write(STDERR_FILENO, "Cannot read file.\n", 18);
		return (1);
	}
	while ((read_size = read(fildes, buf, BUF_SIZE)))
		write(STDOUT_FILENO, buf, read_size);
	if (close(fildes))
		return (1);
	return (0);
}
