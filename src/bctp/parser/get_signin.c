#include "parser.h"

void	*get_signin(char *request, unsigned int req_len)
{
	t_signin	*signin;
	unsigned int	header_count;

	if (req_len < 2)
		return ((void *)0);
	request++;
	req_len -= 2;
	header_count = (unsigned int)*request++;
	signin = (t_signin *)malloc(sizeof(t_signin));
	*signin = (t_signin){0, 0, 0};
	while (header_count && req_len)
	{
		if (req_len < 2 || req_len < 2 + *(request + 1)) {
			free(signin);
			return ((void *)0);
		}
		if (*request == ID_TYPE && !signin->id_type) {
			request += 2;
			signin->id_type = *request++;
			req_len -= 3;
		}
		else if (*request == ID && !signin->id) {
			if (req_len - 2 < (unsigned int)*(++request)) {
				free(signin);
				return ((void *)0);
			}
			signin->id = ft_substr(request, 1, (unsigned int)*request);
			req_len -= 2 + *request;
			request += *request + 1;
		}
		else if (*request == PASSWORD && !signin->password) {
			if (req_len - 2 < (unsigned int)*(++request)) {
				free(signin);
				return ((void *)0);
			}
			signin->password = ft_substr(request, 1, (unsigned int)*request);
			req_len -= 2 + *request;
			request += *request + 1;
		}
		else {
			free(signin);
			return ((void *)0);
		}
		header_count--;
	}
	if (header_count || req_len) {
		free(signin);
		return ((void *)0);
	}
	return ((void *)signin);
}
