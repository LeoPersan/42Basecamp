int	ft_iterative_power(int nb, int power)
{
	int	total;

	if (power == 0)
		return (1);
	if ((nb == 0 && power == 0) || power < 0)
		return (0);
	total = 1;
	while (power--)
		total *= nb;
	return (total);
}
