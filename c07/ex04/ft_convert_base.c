/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 16:16:53 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/10 06:37:09 by cacharle         ###   ########.fr       */
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


int	position_in_base(char digit, char *base)
{
	int	i;

	i = 0;
	while (base[i] != digit)
		i++;
	return (i);
}

// CHECK THE STR NOT JUST THE BASE (you idiot)
int	ft_atoi_base(char *str, char *base)
{
	int	radix;
	int	i;
	int	j;
	int	nb;

	if (!check_base(base))
		return (0);
	nb = 0;
	radix = 0;
	while (base[radix])
		radix++;
	i = 0;
	while (str[i])
		i++;
	j = 0;
	while (--i >= 0)
	{
		nb += ft_pow(radix, i) * position_in_base(str[j], base);
		j++;
	}
	return (nb);
}

int		some_strlen(char *str)
{
	int	counter;

	counter = 0;
	while (str[counter])
		counter++;
	return (counter);
}

char	*to_base(int nbr, char *base)
{
	int				radix;
	int				i;
	unsigned int	nbu;
	char			rev_digits[1024];
	char			*ret;
	int				j;
	int	is_negative;

	/*if (!check_base(base))*/
		/*return (NULL);*/
	radix = some_strlen(base);
	nbu = nbr;
	is_negative = 0;
	if (nbr < 0)
	{
		is_negative = 1;
		nbu = -nbr;
	}
	i = 0;
	printf("%d %s %d\n", radix, base, nbr);
	while (nbu > 0)
	{
		printf("%u\n", nbu % radix);
		rev_digits[i] = base[nbu % radix];
		nbu /= radix;
		i++;
	}
	ret = malloc(sizeof(char) * i + (is_negative ? 1 : 0));
	j = 0;
	if (is_negative)
	{
		ret[0] = '-';
		j++;
	}
	while (i-- > 0)
		ret[j++] = rev_digits[i];
	ret[j] = '\0';
	for (int i = 0; i < 4; i++)
		printf("%c ", rev_digits[i]);
	printf("\n");
	for (int i = 0; i < 4; i++)
		printf("%c ", ret[i]);
	printf("\n");
	return (ret);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		converted_nb;

	int nb;
	return NULL;

}
