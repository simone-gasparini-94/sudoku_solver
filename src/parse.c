#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include "parse.h"
#include "get_next_line.h"

static char	*create_string_with_path(char *s);
static void	populate_grid(int grid[GRID_SIZE][GRID_SIZE], int fd);

int	check_argc(int argc)
{
	if (argc != 2)
	{
		fprintf(stderr, "Wrong number of arguments\n");
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
	populate_grid(grid, fd);
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

static void	populate_grid(int grid[GRID_SIZE][GRID_SIZE], int fd)
{
	char	*s;
	size_t	i, j;

	i = 0;
	while (i < GRID_SIZE)
	{
		s = get_next_line(fd);
		j = 0;
		while (j < GRID_SIZE)
		{
			grid[i][j] = s[j] - '0';
			j++;
		}
		free(s);
		i++;
	}
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
