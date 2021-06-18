#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*range;

	range = (int *)malloc((max - min) * sizeof(int));
	i = 0;
	while (min < max)
		range[i++] = min++;
	return (range);
}
