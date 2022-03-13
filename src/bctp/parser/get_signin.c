#include "parser.h"

static int	string_header(char header, t_signin *s, char *value, unsigned int value_len)
{
	if (header == ID && !s->id)
		s->id = ft_substr(value, 0, value_len);
	else if (header == PASSWORD && !s->password)
		s->password = ft_substr(value, 0, value_len);
	else
		return (0);
	return (1);
}

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
	if (!signin)
		return ((void *)0);
	*signin = (t_signin){0, 0, 0};
	while (header_count && req_len)
	{
		if (req_len < 2 || req_len < 2 + *(request + 1))
			return ((void *)gets_crash(signin));
		if (*request == ID_TYPE && !signin->id_type)
			signin->id_type = *request;
		else if (!string_header(*request, signin, request + 2, *(request  + 1))) {
			return ((void *)gets_crash(signin));
		header_count--;
		req_len -= *(request + 1) + 2;
		request += *(request + 1) + 2;
	}
	if (header_count || req_len)
		return ((void *)gets_crash(signin));
	return ((void *)signin);
}
