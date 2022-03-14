#include "parser.h"

void	*gets_crash(void *mem)
{
	free(mem);
	return (0);
}
