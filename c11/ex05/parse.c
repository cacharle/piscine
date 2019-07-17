/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 08:05:59 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/17 08:35:50 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	parse(int argc, char **argv)
{
	int i;

	if (argc != 4)
		return (-1);
	if (argv[2][0] == '+')
		i = 0;
	else if (argv[2][0] == '-')
		i = 1;
	else if (argv[2][0] == '*')
		i = 2;
	else if (argv[2][0] == '/')
		i = 3;
	else if (argv[2][0] == '%')
		i = 4;
	else
		 i = -2;
	return (i);
}

/*int	make_operation(int x, int y, int (*operator)(int, int))*/
/*{*/

	/*retu*/

/*}*/
