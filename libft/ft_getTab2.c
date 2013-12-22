
#include "libft.h"

void	ft_getTab2(int ***tab,int height, int width)
{
	int	i;
	int	x;

	**tab = malloc(sizeof(**tab) * height);
	while (i < height)
	{
		x = 0;
		*tab[i] = malloc(sizeof(**tab) * width);
		while (x < width)
		{
			*tab[i][x] = 0;
			x++;
		}
		i++;
	}
}
