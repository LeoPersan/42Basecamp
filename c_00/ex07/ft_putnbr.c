#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	int	character[11];
	int	length;
	int	is_negative;

	if (nb == 0)
		ft_putchar('0');
	is_negative = 0;
	if (nb < 0)
	{
		is_negative = 1;
		nb *= -1;
	}
	length = 0;
	while (nb != 0)
	{
		character[length] = nb % 10;
		nb = nb / 10;
		length++;
	}
	if (is_negative)
		ft_putchar('-');
	while (length-- > 0)
	{
		ft_putchar('0' + character[length]);
	}
}
