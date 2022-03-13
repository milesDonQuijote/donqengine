#include "parser.h"

int	gets_crash(void *mem)
{
	free(mem);
	return (0);
}
