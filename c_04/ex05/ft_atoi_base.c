int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}

int	validate(char *base)
{
	int	i;

	while (*base)
	{
		i = 1;
		while (*(base + i))
			if (*base == *(base + i++))
				return (0);
		if (*base == ' '
			|| (*base >= 9 && *base <= 13)
			|| *base == '-'
			|| *base == '+')
			return (0);
		base++;
	}
	return (1);
}

char	*char_to_signal(char *str, int *is_positive)
{
	*is_positive = 1;
	while (*str == '-' || *str == '+')
		if (*(str++) == '-')
			*is_positive *= -1;
	return (str);
}

int	convert_base(char *str, char *base, int	*num)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == *str)
		{
			*num = i;
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_atoi_base(char *str, char *base)
{
	int	total;
	int	signal;
	int	num;

	if (!validate(base))
		return (0);
	while ((*str == ' ' || (*str >= 9 && *str <= 13)))
		str++;
	str = char_to_signal(str, &signal);
	total = 0;
	while (*str && convert_base(str, base, &num))
	{
		total = (total * ft_strlen(base)) + (num * signal);
		str++;
	}
	return (total);
}
