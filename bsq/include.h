/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 13:17:32 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/24 11:51:17 by samzur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_H
# define INCLUDE_H

# define TRUE 1
# define FALSE 0
# define INIT_BUF_SIZE 2
# define GROWTH_FACTOR 2
# define EMPTY 1
# define OBSTACLE 0
# define FILLED -1

typedef struct	s_terrain
{
	int	rows;
	int	columns;
	int **matrix;
}				t_terrain;

typedef struct	s_parsed_terrain
{
	char		empty;
	char		obstacle;
	char		filled;
	t_terrain	*terrain;
}				t_parsed_terrain;

typedef struct	s_cell
{
	int	y;
	int	x;
	int	value;
}				t_cell;

/*
** helper.c - previously made functions
*/

char			*read_file(int fildes);
char			*ft_memcat(char *file, char *buf, int file_size,
							int read_size);
char			*realloc_buf(char *buf, int	buf_size);
int				ft_natoi(char *str, unsigned int n);
void			ft_putchar(char c);

/*
** algo.c - solve the thing
*/

int				ft_min(int nb1, int nb2, int nb3);
t_cell			solve(t_terrain *terrain);
void			solve_and_complete(t_terrain *terrain);

/*
** parse.c - map parsing
*/

int				parse_file(char *filename, t_parsed_terrain *pterrain);
int				parse_fildes(int fildes, t_parsed_terrain *pterrain);
int				parse(char *file, t_parsed_terrain *pterrain);

/*
** parse_helper.c - parse.c sub functions
*/

int				*set_row(char *file, t_parsed_terrain *pterrain, int y);
int				set_dimensions(char *file, t_parsed_terrain *pterrain);
int				parse_header(char *file, t_parsed_terrain *pterrain);

/*
** terrain.c - terrain manipulation
*/

void			destroy_terrain(t_terrain *terrain);
void			print_terrain(t_parsed_terrain *parsed_terrain);
int				terrain_to_string(t_parsed_terrain *pterrain, char *str);

/*
** utils.c - random stuff I need to put somewhere
*/

void			parse_stdin_print(void);
void			parse_file_print(char *filename);
int				count_lines(char *file);
int				ft_line_len(char *str);

#endif
