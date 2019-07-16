char	ctoi(char c)
{
	return (c - '0');
}

int		ft_strlen(const char *str)
{
	int	counter;

	counter = 0;
	while (*str >= '0' && *str <= '9')
	{
		counter++;
		str++;
	}
	return (counter);
}

int		pow10(int exponent)
{
	int	accumulator;

	accumulator = 1;
	while (exponent > 0)
	{
		accumulator *= 10;
		exponent--;
	}
	return (accumulator);
}

int		ft_atoi(const char *str)
{
	int	nb;
	int	i;
	int	is_negative;

	while (*str == ' ' || *str == '\t'|| *str == '\n'
		   || *str == '\v'|| *str == '\f'|| *str == '\r')
		str++;
	if (*str == '-')
		is_negative = 1;
	else
		is_negative = 0;
	if (*str == '-' || *str == '+')
	{
		str++;
	}
	nb = 0;
	i = ft_strlen(str) - 1;
	while (*str >= '0' && *str <= '9')
	{
		nb += pow10(i) * ctoi(*str);
		i--;
		str++;
	}
	if (is_negative)
		nb = -nb;
	return (nb);
}
