/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 22:18:43 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/02 22:33:52 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void);

void	ft_print_alphabet(void)
{
	char	letter;

	letter = 'a';
	while (letter != 'z' + 1)
	{
		write(1, &letter, 1);
		letter++;
	}
}

int		main(void)
{
	ft_print_alphabet();
	return (0);
}
