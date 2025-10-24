#include <stdio.h>
#include "parse.h"

void	print_grid(int grid[GRID_SIZE][GRID_SIZE])
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < GRID_SIZE)
	{
		j = 0;
		while (j < GRID_SIZE)
		{
			printf("%d ", grid[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
