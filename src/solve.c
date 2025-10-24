#include <stdio.h>
#include <stdlib.h>
#include "parse.h"
#include "print.h"

void	solve(int grid[GRID_SIZE][GRID_SIZE], int idx)
{
	if (idx == GRID_SIZE * GRID_SIZE)
		print_grid(grid);

}
