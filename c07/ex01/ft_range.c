#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*ptr;

	if (min >= max)
	{
		return (NULL);
	}
	ptr = malloc((max - min) * 4);
	if (!ptr)
	{
		return (NULL);
	}
	i = 0;
	while (min < max)
	{
		ptr[i] = min;
		i++;
		min++;
	}
	return (ptr);
}