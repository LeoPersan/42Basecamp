int	sum_view_aux(int *cell, int step)
{
	int	i;
	int	qty;
	int	taller_tw;

	i = 0;
	qty = 0;
	taller_tw = 0;
	while (i < 4)
	{
		if (*cell > taller_tw)
		{
			taller_tw = *cell;
			qty++;
		}
		cell += step;
		i++;
	}
	return (qty);
}

int	sum_view(int ground[4][4], int direction, int position)
{
	int	qty;

	qty = 0;
	if (direction == 0)
		qty = sum_view_aux(&ground[0][position], 4);
	else if (direction == 1)
		qty = sum_view_aux(&ground[3][position], -4);
	else if (direction == 2)
		qty = sum_view_aux(&ground[position][0], 1);
	else if (direction == 3)
		qty = sum_view_aux(&ground[position][3], -1);
	return (qty);
}

int	check_ground(int rules[4][4], int ground[4][4])
{
	int	dir;
	int	position;

	dir = 0;
	while (dir < 4)
	{
		position = 0;
		while (position < 4)
		{
			if (rules[dir][position] != sum_view(ground, dir, position))
				return (0);
			position++;
		}
		dir++;
	}
	return (1);
}
