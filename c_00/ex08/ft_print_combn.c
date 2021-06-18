#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_put_number(int *number)
{
	int	i;

	i = 0;
	while (number[i] != 'z')
	{
		ft_putchar('0' + number[i]);
		i++;
	}
}

int	ft_next_number(int *number, int n)
{
	int	i;
	int	loop;

	loop = 0;
	i = n - 1;
	while (i >= 0)
	{
		if (number[i] < 10 + i - n)
		{
			number[i]++;
			loop = 1;
			i++;
			while (i < n)
			{
				number[i] = number[i - 1] + 1;
				i++;
			}
			break ;
		}
		i--;
	}
	return (loop);
}

void	ft_print_combn(int n)
{
	int	number[11];
	int	i;
	int	loop;

	number[n] = 'z';
	i = 0;
	while (i < n)
	{
		number[i] = i;
		i++;
	}
	loop = 1;
	while (loop)
	{
		ft_put_number(number);
		loop = ft_next_number(number, n);
		if (loop)
		{
			ft_putchar(',');
			ft_putchar(' ');
		}
	}
}
