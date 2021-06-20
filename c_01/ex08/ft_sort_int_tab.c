#include <unistd.h>
#include <stdio.h>

void	quick_sort(int *tab, int start, int end)
{
	int	pivo;
	int	aux;
	int	s;
	int	e;

	s = start;
	e = end;
	pivo = tab[(s + e) / 2];
	while (s < e)
	{
		while (tab[s] < pivo)
			s++;
		while (tab[e] > pivo)
			e--;
		if (s <= e)
		{
			aux = tab[e];
			tab[e--] = tab[s];
			tab[s++] = aux;
		}
	}
	if (start < e)
		quick_sort(tab, start, e);
	if (end > s)
		quick_sort(tab, s, end);
}

void	ft_sort_int_tab(int *tab, int size)
{
	quick_sort(tab, 0, size - 1);
}
