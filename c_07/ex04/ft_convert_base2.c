int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_validate(char *base)
{
	int	i;

	if (ft_strlen(base) < 2)
		return (0);
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

int	ft_char_to_int_by_base(char *str, char *base)
{
	int	i;

	i = -1;
	while (base[++i])
		if (base[i] == *str)
			return (i);
	return (-1);
}

char	*ltrim(char *str)
{
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	return (str);
}
