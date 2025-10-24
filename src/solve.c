#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "parse.h"
#include "print.h"

static bool	is_valid(int grid[GRID_SIZE][GRID_SIZE], int row, int col, int n);

void	solve(int grid[GRID_SIZE][GRID_SIZE], int idx)
{
	int	n;
	int	row;
	int	col;
	
	if (idx == GRID_SIZE * GRID_SIZE)
	{
		print_grid(grid);
		return ;
	}
	row = idx / GRID_SIZE;
	col = idx % GRID_SIZE;
	if (grid[row][col] != 0)
		solve(grid, idx + 1);
	else if (grid[row][col] == 0)
	{
		n = 1;
		while (n <= GRID_SIZE)
		{
			if (is_valid(grid, row, col, n) == true)
			{
				grid[row][col] = n;
				solve(grid, idx + 1);
				grid[row][col] = 0;
			}
			n++;
		}
	}
}

static bool	is_valid(int grid[GRID_SIZE][GRID_SIZE], int row, int col, int n)
{
	int	i, j, start_row, start_col;

	i = 0;
	while (i < GRID_SIZE)
	{
		if (grid[row][i] == n)
			return (false);
		i++;
	}
	i = 0;
	while (i < GRID_SIZE)
	{
		if (grid[i][col] == n)
			return (false);
		i++;
	}
	start_row = row - row % 3;
	start_col = col - col % 3;
	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			if (grid[start_row + i][start_col + j] == n)
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}
