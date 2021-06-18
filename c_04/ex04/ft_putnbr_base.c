#include <unistd.h>

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}

int	validate(char *base)
{
	int	i;

	if (ft_strlen(base) < 2)
		return (0);
	while (*base)
	{
		if (*base == '-' || *base == '+')
			return (0);
		i = 1;
		while (*(base + i))
		{
			if (*base == *(base + i))
				return (0);
			i++;
		}
		base++;
	}
	return (1);
}

void	ft_putnbr_base(int nb, char *base)
{
	long int	nb_aux;

	if (!validate(base))
		return ;
	nb_aux = nb;
	if (nb_aux < 0)
	{
		write(1, "-", 1);
		nb_aux *= -1;
	}
	if (nb_aux >= ft_strlen(base))
	{
		ft_putnbr_base(nb_aux / ft_strlen(base), base);
		ft_putnbr_base(nb_aux % ft_strlen(base), base);
	}
	else
	{
		write(1, &base[nb_aux], 1);
	}
}
