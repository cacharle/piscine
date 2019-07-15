/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 15:24:19 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/15 10:11:05 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "ex02/ft_abs.h"
#include "ex03/ft_point.h"
#include "ex04/ft_strs_to_tab.c"
#include "ex05/ft_show_tab.c"

int main()
{
	printf("%d\n", ABS(42));
	printf("%d\n", ABS(-42));
	printf("%d\n", ABS(30 - 42));
	printf("%d\n", ABS(50 * -45));
	printf("%d\n", ABS(-24) - 20);

	printf("--------------------\n");
	char **a = (char**)malloc(sizeof(char*) * 3);
	a[0] = (char*)malloc(sizeof(char) * 1024);
	a[1] = (char*)malloc(sizeof(char) * 1024);
	a[2] = (char*)malloc(sizeof(char) * 1024);
	strcpy(a[0], "ieSrBXBI5d4rW9O2");
	strcpy(a[1], "eadLhPjehRMwjqv9JJ7Q0WiLTBoVxsLx");
	strcpy(a[2], "MKynFC5rJwCJ0jdD");
	t_stock_str *b = ft_strs_to_tab(3, a);
	for (int i = 0; b[i].str != 0; i++)
		printf("%s \n%s | %d\n", b[i].str, b[i].copy, b[i].size);

	b[0].copy = "bafj";
	ft_show_tab(b);
	/*for (int i = 0; b[i].str != 0; i++)*/
		/*free(b[i].copy);*/
	/*free(b);*/
	/*free(a[0]);*/
	/*free(a[1]);*/
	/*free(a[2]);*/
	/*free(a);*/

	return 0;
}
