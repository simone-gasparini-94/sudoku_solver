#include <stdio.h>
#include "parse.h"

void	print_grid(int grid[GRID_SIZE][GRID_SIZE])
{
	size_t	i;
	size_t	j;

	printf("\n");
	i = 0;
	while (i < GRID_SIZE)
	{
		j = 0;
		while (j < GRID_SIZE)
		{
			if (grid[i][j] == 0)
				printf("\033[90m%d \033[0m", grid[i][j]);
			else
				printf("%d ", grid[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
