#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include "parse.h"
#include "print.h"
#include "get_next_line.h"

static char	*create_string_with_path(char *s);
static int	populate_grid(int grid[GRID_SIZE][GRID_SIZE], int fd);

int	check_argc(int argc)
{
	if (argc != 2)
	{
		fprintf(stderr, "wrong number of arguments\n");
		return (1);
	}
	return (0);
}

int	parse_file(int grid[GRID_SIZE][GRID_SIZE], char *s)
{
	char	*str;
	int		fd;

	str = create_string_with_path(s);
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "%s: %s\n", s, strerror(errno));
		return (1);
	}
	if (populate_grid(grid, fd) == 1)
	{
		fprintf(stderr, "invalid grid\n");
		return (1);
	}
	close(fd);
	return (0);
}

static char	*create_string_with_path(char *s)
{
	char	*new;
	char	*path;
	size_t	len;

	path = strdup("assets/");
	len = strlen(path) + strlen(s);
	new = calloc(len + 1, sizeof(char));
	if (new == NULL)
	{
		perror("malloc");
		return (NULL);
	}
	strcpy(new, path);
	strcat(new, s);
	free(path);
	return (new);
}

static int	populate_grid(int grid[GRID_SIZE][GRID_SIZE], int fd)
{
	char	*s;
	size_t	i, j;

	i = 0;
	while (i < GRID_SIZE)
	{
		s = get_next_line(fd);
		if (s == NULL)
			return (1);
		j = 0;
		while (j < GRID_SIZE)
		{
			if (s[j] == '\0')
				return (1);
			grid[i][j] = s[j] - '0';
			j++;
		}
		free(s);
		i++;
	}
	print_grid(grid);
	return (0);
}
