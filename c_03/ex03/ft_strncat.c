char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int				d_lenght;
	unsigned int	i;

	d_lenght = 0;
	while (dest[d_lenght] != '\0')
		d_lenght++;
	i = 0;
	while (i < nb && src[i] != '\0')
	{
		dest[d_lenght + i] = src[i];
		i++;
	}
	dest[d_lenght + i] = '\0';
	return (dest);
}
