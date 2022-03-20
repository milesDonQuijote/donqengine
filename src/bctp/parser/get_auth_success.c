#include "parser.h"

void	*get_auth_success(char *request, unsigned int req_len)
{
	char		key;
	unsigned int	header_count;

	if (req_len < 2 || !request)
		return ((void *)0);
	key = 0;
	request++;
	req_len -= 2;
	header_count = (unsigned int)*request++;
	while (header_count && req_len)
	{
		if (req_len < 2 || req_len < 2 + *(request + 1))
			return ((void *)gets_crash(key));
		if (*request == KEY && !key)
			key = ft_substr(request, 2, *(request + 1));
		else
			return ((void *)gets_crash(key));
		header_count--;
		req_len -= *(request + 1) + 2;
		request += *(request + 1) + 2;
	}
	if (header_count || req_len)
		return ((void *)gets_crash(key));
	return ((void *)key);
}
