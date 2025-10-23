#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

int	main(int argc, char *argv[])
{
	int	fd;

	if (argc != 2)
	{
		fprintf(stderr, "Wrong number of arguments\n");
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "%s: %s\n", argv[1], strerror(errno));;
		return (2);
	}
	close(fd);
}
