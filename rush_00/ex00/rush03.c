void	ft_putchar(char c);

void	print_rows(int row, int x, char corner, char middle)
{
	if (row == 1 || row == x)
	{
		ft_putchar(corner);
	}
	else
	{
		ft_putchar(middle);
	}
}

void	print_columns(int row, int column, int x, int y)
{
	if (column == 1)
	{
		print_rows(row, x, 'A', 'B');
	}
	else if (column == y)
	{
		print_rows(row, x, 'C', 'B');
	}
	else
	{
		print_rows(row, x, 'B', ' ');
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
			print_columns(row, column, x, y);
			column++;
		}
		row++;
		column = 1;
		ft_putchar('\n');
	}
}
