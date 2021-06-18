#include <unistd.h>

int	rush(int rules[3][4][4], int ground[4][4]);

int	compare_chars_quantities(char *arg, int qty)
{
	int	chars;

	chars = 0;
	while (arg[chars])
		chars++;
	if (chars != qty)
		return (0);
	return (1);
}

int	str_to_vector_int(char *arg, int rules[3][4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (*arg < '1' || *arg > '4')
				return (0);
			rules[0][i][j] = *arg - '0';
			arg++;
			if (*arg != ' ' && *arg != '\0')
				return (0);
			arg++;
			j++;
		}
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	rules[3][4][4];
	int	ground[4][4];

	if (
		argc == 2
		&& compare_chars_quantities(argv[1], 31)
		&& str_to_vector_int(argv[1], rules)
		&& rush(rules, ground)
	)
		return (0);
	write(2, "Error\n", 6);
	return (1);
}
