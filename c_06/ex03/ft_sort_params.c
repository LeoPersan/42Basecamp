#include <unistd.h>

void	sort_params(int argc, char *argv[])
{
	int		i;
	int		j;
	char	*arg;

	i = 1;
	while (i < argc - 1)
	{
		j = 0;
		while (argv[i][j] && argv[i + 1][j] && argv[i][j] == argv[i + 1][j])
			j++;
		if (argv[i][j] > argv[i + 1][j])
		{
			arg = argv[i + 1];
			argv[i + 1] = argv[i];
			argv[i] = arg;
			i = 1;
		}
		else
			i++;
	}
}

int	main(int argc, char *argv[])
{
	int		i;
	int		j;

	sort_params(argc, argv);
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			write(1, &argv[i][j], 1);
			j++;
		}
		i++;
		write(1, "\n", 1);
	}
	return (0);
}
