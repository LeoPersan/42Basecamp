char	*ft_strcat(char *dest, char *src)
{
	char	*dest_cpy;

	dest_cpy = dest;
	while (*dest_cpy != '\0')
		dest_cpy++;
	while (*src != '\0')
		*(dest_cpy++) = *(src++);
	*dest_cpy = '\0';
	return (dest);
}
