/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 22:27:12 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/02 22:31:18 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void);

void	ft_print_reverse_alphabet(void)
{
	char letter;

	letter = 'z';
	while (letter != 'a' - 1)
	{
		write(1, &letter, 1);
		letter--;
	}
}

int		main(void)
{
	ft_print_reverse_alphabet();
	return (0);
}
