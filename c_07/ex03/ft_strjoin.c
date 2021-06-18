#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_all_str_lens(int size, char **strs, char *sep)
{
	int	i;
	int	chars;

	if (size < 1)
		return (1);
	i = 0;
	chars = 0;
	while (i < size - 1)
	{
		chars += ft_strlen(strs[i]);
		chars += ft_strlen(sep);
		i++;
	}
	return (chars + ft_strlen(strs[i]));
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		j;
	int		s;
	int		chars;
	char	*join;

	chars = ft_all_str_lens(size, strs, sep);
	join = (char *)malloc(chars * sizeof(char));
	i = 0;
	j = 0;
	while (i < size - 1)
	{
		while (*strs[i])
			join[j++] = *strs[i]++;
		s = 0;
		while (sep[s])
			join[j++] = sep[s++];
		i++;
	}
	if (i < size)
		while (*strs[i])
			join[j++] = *strs[i]++;
	return (join);
}
