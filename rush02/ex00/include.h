/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiacono <yiacono@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 07:31:47 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/21 14:51:26 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_H
# define INCLUDE_H

# define TRUE 1
# define FALSE 0
# define BUF_SIZE 1024
# define REQUIRED_SIZE 32

typedef long long int	t_max_nbr;
struct		s_entry
{
	t_max_nbr	key;
	char		*value;
};
typedef struct s_entry	t_entry;
typedef t_entry* t_dict;
/*
** helper.c - previously made functions
*/

int			read_file(int fildes, char **file);
char		*ft_memcat(char *file, char buf[BUF_SIZE], int file_size,
					int buf_size);
char		*ft_strndup(char *src, int n);
void		ft_putstr(char *str);

/*
** convert.c - Convert number to string
*/

int			convert(t_max_nbr nb, t_dict dict);

/*
** parse.c - Dictionnary reading and converting
*/

t_dict		parse_dict(char *file, int file_size);
t_dict		parse_dict_file(char *filename);
int			set_entry(char *line, t_entry *entry);
char		*filtered_value(char *str);
int			count_lines(char *file);

/*
** dict.c - operation on dict
*/

void		sort_dict(t_dict dict);
int			required_values(t_dict dict);
int			as_uniq_keys(t_dict dict);
void		destroy_dict(t_dict dict, int size);

/*
** error.c - Error checking
*/

t_max_nbr	strict_atoi(char *str);
int			print_error_if(int status, t_dict dict);
int			print_dict_error_if(int status, t_dict dict);

#endif
