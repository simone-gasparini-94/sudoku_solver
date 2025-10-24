#include "parse.h"
#include "solve.h"

int	main(int argc, char *argv[])
{
	int	grid[GRID_SIZE][GRID_SIZE];

	if (check_argc(argc) == 1)
		return (1);
	if (parse_file(grid, argv[1]) == 1)
		return (2);
	solve(grid, 0);
	return (0);
}
