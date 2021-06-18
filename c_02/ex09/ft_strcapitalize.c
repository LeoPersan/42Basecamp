char	ft_strlowcase(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

char	ft_strupcase(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

int	is_capital(char c)
{
	if (
		(c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9')
	)
		return (0);
	return (1);
}

char	*ft_strcapitalize(char *str)
{
	int		i;
	char	prev;

	i = 0;
	prev = '\0';
	while (str[i] != '\0')
	{
		if (is_capital(prev))
			str[i] = ft_strupcase(str[i]);
		else
			str[i] = ft_strlowcase(str[i]);
		prev = str[i];
		i++;
	}
	return (str);
}
