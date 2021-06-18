#include <unistd.h>

int	check_ground(int rules[4][4], int ground[4][4]);

void	write_ground(int ground[4][4])
{
	int		row;
	int		column;
	char	c;

	row = 0;
	while (row < 4)
	{
		column = 0;
		while (column < 4)
		{
			c = '0' + ground[row][column];
			write(1, &c, 1);
			if (column < 3)
				write(1, " ", 1);
			column++;
		}
		row++;
		write(1, "\n", 1);
	}
}

int	fill_board(int rules[3][4][4], int ground[4][4], int row, int column)
{
	int	value;

	if (row == 4)
		return (check_ground(rules[0], ground));
	if (column == 4)
		return (fill_board(rules, ground, row + 1, 0));
	value = 1;
	while (value < 5)
	{
		if (!rules[1][row][value - 1] && !rules[2][column][value - 1])
		{
			rules[1][row][value - 1] = 1;
			rules[2][column][value - 1] = 1;
			ground[row][column] = value;
			if (fill_board(rules, ground, row, column + 1))
				return (1);
			rules[1][row][value - 1] = 0;
			rules[2][column][value - 1] = 0;
		}
		value++;
	}
	return (0);
}

void	start(int rules[3][4][4], int ground[4][4])
{
	int	row;
	int	column;

	row = 0;
	while (row < 4)
	{
		column = 0;
		while (column < 4)
		{
			ground[row][column] = 0;
			rules[1][row][column] = 0;
			rules[2][row][column] = 0;
			column++;
		}
		row++;
	}
}

int	rush(int rules[3][4][4], int ground[4][4])
{
	start(rules, ground);
	if (fill_board(rules, ground, 0, 0))
	{
		write_ground(ground);
		return (1);
	}
	else
		return (0);
}
