void	ft_putchar(char c);

void	print_columns(int column, int y, char corner, char middle)
{
	if (column == 1 || column == y)
	{
		ft_putchar(corner);
	}
	else
	{
		ft_putchar(middle);
	}
}

void	print_rows(int row, int column, int x, int y)
{
	if (row == 1)
	{
		print_columns(column, y, 'A', 'B');
	}
	else if (row == x)
	{
		print_columns(column, y, 'C', 'B');
	}
	else
	{
		print_columns(column, y, 'B', ' ');
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
			print_rows(row, column, x, y);
			column++;
		}
		row++;
		column = 1;
		ft_putchar('\n');
	}
}
