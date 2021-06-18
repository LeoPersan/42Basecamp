#include <unistd.h>

int	main(int argc, char *argv[])
{
	int i;
	int j;

	i = argc - 1;
	while (i > 0)
	{
		j = 0;
		while (argv[i][j])
			write(1, &argv[i][j++], 1);
		i--;
		write(1, "\n", 1);
	}
	return (0);
}
