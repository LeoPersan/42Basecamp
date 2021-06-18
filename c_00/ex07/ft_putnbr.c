#include <unistd.h>

void	ft_putnbr(int nb)
{
	char		c;
	long int	nb_aux;

	nb_aux = nb;
	if (nb_aux < 0)
	{
		write(1, "-", 1);
		nb_aux *= -1;
	}
	if (nb_aux > 9)
	{
		ft_putnbr(nb_aux / 10);
		ft_putnbr(nb_aux % 10);
	}
	else
	{
		c = '0' + nb_aux;
		write(1, &c, 1);
	}
}
