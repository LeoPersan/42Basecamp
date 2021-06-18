int	ft_is_prime(int nb)
{
	int	i;

	if (nb < 2)
		return (0);
	i = 2;
	while (i <= nb / i)
		if (nb % i++ == 0)
			return (0);
	return (1);
}
