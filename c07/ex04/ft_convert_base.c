/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 16:16:53 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/09 09:05:47 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+' || base[i] == ' '
			|| base[i] == '\t' || base[i] == '\n' || base[i] == '\v'
			|| base[i] == '\f' || base[i] == '\r')
			return (0);
		j = 0;
		while (base[j])
		{
			if (j != i && base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (1);
}

int		ft_pow(int base, int exponent)
{
	int	accumulator;

	accumulator = 1;
	while (exponent-- > 0)
		accumulator *= base;
	return (accumulator);
}

int		ft_atoi_base(char *nbr, char *base)
{

}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		converted_nb;
	char	*converted_to

	if (!check_base(base_from) || !check_base(base_to))
		return (NULL);
	converted_nb = ft_atoi_base(nbr, base_from);
	printf("%d\n", convert_nb);
	/*converted_to = ft_itoa_base(converted_nb, base_to);*/
	/*return (converted_to);*/
}
