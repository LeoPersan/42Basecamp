#include <stdlib.h>
int		ft_strlen(char *str);
int		ft_validate(char *base);
char	*char_to_signal(char *str, int *is_positive);
int		ft_char_to_int_by_base(char *str, char *base);
char	*ltrim(char *str);

void	ft_putnbr_base(long int nb, char *base, char *output)
{
	while (*output)
		output++;
	if (nb >= ft_strlen(base))
	{
		ft_putnbr_base(nb / ft_strlen(base), base, output);
		ft_putnbr_base(nb % ft_strlen(base), base, output);
		return ;
	}
	*(output++) = base[nb];
	*(output++) = '\0';
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int			num;
	int			signal;
	long int	total;
	char		*output;

	if (!ft_validate(base_from) || !ft_validate(base_to))
		return (NULL);
	nbr = ltrim(nbr);
	nbr = char_to_signal(nbr, &signal);
	total = 0;
	num = ft_char_to_int_by_base(nbr, base_from);
	while (*nbr && num >= 0)
	{
		total = (total * ft_strlen(base_from)) + num;
		num = ft_char_to_int_by_base(++nbr, base_from);
	}
	output = (char *)malloc(34 * sizeof(char));
	num = 0;
	if (signal < 0)
		output[num++] = '-';
	output[num] = '\0';
	ft_putnbr_base(total, base_to, output);
	return (output);
}
