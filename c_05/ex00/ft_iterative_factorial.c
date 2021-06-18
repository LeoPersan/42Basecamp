int	ft_iterative_factorial(int nb)
{
	long int	total;

	if (nb < 0)
		return (0);
	total = 1;
	while (nb > 0)
		total *= nb--;
	return (total);
}
