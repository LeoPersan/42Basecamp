#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	aux;

	i = 0;
	aux = 0;

	while (i < size / 2)
	{
		aux = tab[size - 1 - i];
		tab[size - 1 - i] = tab[i];
		tab[i] = aux;
		i++;
	}
}
