#include "parse.h"

int	main(int argc, char *argv[])
{
	if (check_argc(argc) == 1)
		return (1);
	if (parse_file(argv[1]) == 1)
		return (2);
}
