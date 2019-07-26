/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 14:44:30 by exam              #+#    #+#             */
/*   Updated: 2019/07/26 16:34:49 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_H
# define INCLUDE_H

/*
** helper.c
*/

int		ft_strlen(char *str);
int		letter_diff(char a, char b);
int		str_lettercmp(char *s1, char *s2);
void	ft_putstr(char *str);

/*
** helper2.c
*/

int		sorted(char **strs, int cmp(char*, char*));
void	sort_strs(char **strs, int cmp(char*, char*));
int		strlen_cmp(char *s1, char *s2);
void	print_strs(char **strs);

/*
** helper3.c
*/

int		in_charset(char c);
int		count_segment(char *str);
char	**ft_split(char *str);

#endif
