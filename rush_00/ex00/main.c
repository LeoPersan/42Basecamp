#include <unistd.h>

void	rush(int x, int y);

int	str_to_int(char *arg)
{
	int	i;
	int	total;

	i = 0;
	total = 0;
	while (arg[i] != '\0')
	{
		total = (total * 10) + arg[i] - 48;
		i++;
	}
	return (total);
}

int	main(int argc, char *argv[])
{
	int	y;
	int	x;

	x = 0;
	y = 0;
	if (argc == 3)
	{
		x = str_to_int(argv[1]);
		y = str_to_int(argv[2]);
		if (x >= 0 && y >= 0)
		{
			rush(x, y);
			return (0);
		}
	}
	write(2, "Passe dois parâmetros do tipo inteiro positivo!", 48);
	write(2, "\n", 2);
	return (1);
}
