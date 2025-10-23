#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

int	check_argc(int argc)
{
	if (argc != 2)
	{
		fprintf(stderr, "Wrong number of arguments\n");
		return (1);
	}
	return (0);
}

int	parse_file(char *s)
{
	int	fd;

	fd = open(s, O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "%s: %s\n", s, strerror(errno));
		return (1);
	}
	close(fd);
}
