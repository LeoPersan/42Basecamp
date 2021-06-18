char	*ltrim(char *str)
{
	while ((*str == ' ' || (*str >= 9 && *str <= 13)))
		str++;
	return (str);
}

char	*char_to_signal(char *str, int *is_positive)
{
	*is_positive = 1;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			*is_positive *= -1;
		str++;
	}
	return (str);
}

int	ft_atoi(char *str)
{
	int	total;
	int	signal;

	str = ltrim(str);
	str = char_to_signal(str, &signal);
	total = 0;
	while (*str && *str >= '0' && *str <= '9')
	{
		total = (total * 10) + ((*str - '0') * signal);
		str++;
	}
	return (total);
}
