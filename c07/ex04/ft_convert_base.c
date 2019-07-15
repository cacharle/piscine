/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 16:16:53 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/12 12:07:28 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		check_base(char *base);
int		ft_pow(int base, int exponent);
int		position_in_base(char digit, char *base);
int		some_strlen(char *str);

int		from_base(char *str, char *base)
{
	int	radix;
	int	i;
	int	j;
	int	nb;
	int	is_negative;

	while (*str == ' ' || *str == '\t' || *str == '\n'
			|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	is_negative = 0;
	while (*str == '-' || *str == '+')
		if (*str++ == '-')
			is_negative = !is_negative;
	nb = 0;
	radix = 0;
	while (base[radix])
		radix++;
	i = 0;
	while (position_in_base(str[i], base) != -1)
		i++;
	j = 0;
	while (--i >= 0)
		nb += ft_pow(radix, i) * position_in_base(str[j++], base);
	return (is_negative ? -nb : nb);
}

char	*to_base(int nbr, char *base, int radix, int is_negative)
{
	int				i;
	int				j;
	unsigned int	nbu;
	char			rev_digits[1024];
	char			*ret;

	nbu = nbr;
	if (is_negative)
		nbu = -nbr;
	i = nbu == 0 ? 1 : 0;
	rev_digits[0] = base[0];
	while (nbu > 0)
	{
		rev_digits[i] = base[nbu % radix];
		nbu /= radix;
		i++;
	}
	ret = malloc(sizeof(char) * i + (is_negative ? 1 : 0));
	j = 0;
	if (is_negative)
		ret[0] = '-';
	while (i-- + (is_negative ? 1 : 0) > 0)
		ret[j++ + (is_negative ? 1 : 0)] = rev_digits[i];
	ret[j] = '\0';
	return (ret);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		nb;
	char	*parsed_nbr;

	if (!check_base(base_from) || !check_base(base_to))
		return (NULL);
	parsed_nbr = nbr;
	nb = from_base(parsed_nbr, base_from);
	return (to_base(nb, base_to, some_strlen(base_to), nb < 0));
}
