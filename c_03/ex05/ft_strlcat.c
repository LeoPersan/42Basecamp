unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size && dest[i])
		i++;
	if (!dest[i])
	{
		while (i < size - 1 && *src)
			dest[i++] = *(src++);
		dest[i] = 0;
	}
	while (*(src++))
		i++;
	return (i);
}
