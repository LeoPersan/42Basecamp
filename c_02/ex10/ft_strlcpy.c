unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	lenght;

	lenght = 0;
	while (src[lenght] != '\0')
		lenght++;
	i = 0;
	while (i < size && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	if (i >= size)
		i = size - 1;
	while (i < size)
	{
		dest[i] = '\0';
		i++;
	}
	return (lenght);
}
