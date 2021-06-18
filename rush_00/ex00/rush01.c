void	ft_putchar(char c);

void	print(int row, int column, int x, int y)
{
	if ((row == 1 && column == 1) || (row == x && column == y))
	{
		ft_putchar('/');
	}
	else if ((row == 1 && column == y) || (row == x && column == 1))
	{
		ft_putchar('\\');
	}
	else if (column == 1 || column == x || row == 1 || row == x)
	{
		ft_putchar('*');
	}
	else
	{
		ft_putchar(' ');
	}
}

void	rush(int x, int y)
{
	int	row;
	int	column;

	row = 1;
	column = 1;
	while (row <= x)
	{
		while (column <= y)
		{
			print(row, column, x, y);
			column++;
		}
		row++;
		column = 1;
		ft_putchar('\n');
	}
}
