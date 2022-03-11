#include "hcpparser.h"

int	is_hcp(char *str)
{
	int	idx;
	if (!str)
		return (0);
	idx = 0;
	while (str[idx] && str[idx] == PROTOCOL_HEADER[idx])
		idx++;
	return (str[idx] == '\n');
}
