#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	*vector;

	if (min > max)
	{
		range = NULL;
		return (0);
	}
	*range = (int *)malloc((max - min) * sizeof(int));
	if (*range == NULL)
		return (-1);
	vector = *range;
	i = 0;
	while (min < max)
		*(vector++) = min++;
	return (i);
}
