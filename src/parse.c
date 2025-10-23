#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

static char	*create_string_with_path(char *s);

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
	char	*str;
	int		fd;

	str = create_string_with_path(s);
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "%s: %s\n", s, strerror(errno));
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
