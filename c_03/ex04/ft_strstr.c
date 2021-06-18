int	ft_strcmp(char *str, char *to_find)
{
	while (*to_find && *str)
	{
		if (*(str++) != *(to_find++))
			return (0);
	}
	return (1);
}

char	*ft_strstr(char *str, char *to_find)
{
	while (*str)
	{
		if (ft_strcmp(str, to_find))
			return (str);
		str++;
	}
	return (0);
}
