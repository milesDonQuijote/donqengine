#include "parser.h"

void	*get_signup(char *request, unsigned int req_len)
{
	t_signup	*signup;
	unsigned int	header_count;

	if (req_len < 2)
		return ((void *)0);
	request++;
	req_len -= 2;
	header_count = (unsigned int)*request++;
	signup = (t_signup *)malloc(sizeof(t_signup));
	*signup = (t_signup){0, 0, 0, 0, 0};
	while (header_count && req_len)
	{
		if (req_len < 3) { // [header][value_len][value]
			free(signup);
			return ((void *)0);
		}
		if (*request == ID_TYPE && !signup->id_type) {
			request += 2;
			signup->id_type = *request++;
			req_len -= 3;
		}
		else if ((*request == ID && !signup->id) || (*request == PASSWORD && !signup->password) ||
				(*request == NAME && !signup->name) || (*request == SURNAME && !signup->surname)) {
			if (req_len - 3 < (unsigned int)*(++request)) { // [value_len = n] --> n*byte
				free(signup);
				return ((void *)0);
			}
			if (*(request - 1) == ID)
				signup->id = ft_substr(request, 1, (unsigned int)*request);
			else if (*(request - 1) == PASSWORD)
				signup->password = ft_substr(request, 1, (unsigned int)*request);
			else if (*(request - 1) == NAME)
				signup->name = ft_substr(request, 1, (unsigned int)*request);
			else
				signup->surname = ft_substr(request, 1, (unsigned int)*request);
			req_len -= 2 + (int)*request;
			request += *request + 1;
		}
		else {
			free(signup);
			return ((void *)0);
		}
		header_count--;
	}
	if (header_count)
	{
		free(signup);
		return ((void *)0);
	}
	return ((void *)signup);
}
