/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 13:17:32 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/19 15:55:03 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_H
# define INCLUDE_H

# define TRUE 1
# define FALSE 0
# define EMPTY 0
# define OBSTACLE 1

struct s_square
{
	int	size;
	int x;
	int y;
};

struct s_terrain
{
	char	empty;
	char	fill;
	char	obstacle;
	int		size;
	char	*file;
}

typedef struct s_terrain	t_terrain;
typedef struct s_square		t_square;
typedef int					t_bool;

/*
** solve.c - Solve the thing (yes)
*/


/*
** parse.c - Input parsing
** Put file in string, parse it and check if it's valid
*/

t_bool check_input(char *input);

/*
** helper.c - function already made
*/

int		read_file(int fildes, char **file);
char	*ft_memcat(char *file, char buf[BUF_SIZE], int file_size,
					int read_size);



#endif
