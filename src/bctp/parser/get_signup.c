#include "parser.h"

static int	string_header(char header, t_signup *s, char *value, unsigned int value_len)
{
	if (header == NAME && !s->name)
		s->id = ft_substr(value, 0, value_len);
	else if (header == PASSWORD && !s->password)
		s->password = ft_substr(value, 0, value_len);
	else if (header == SURNAME && !s->surname)
		s->surname = ft_substr(value, 0, value_len);
	else if (header == ID && !s->id)
		s->id = ft_substr(value, 0, value_len);
	else
		return (0);
	return (1);
}

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
	if (!signup)
		return ((void *)0);
	*signup = (t_signup){0, 0, 0, 0, 0};
	while (header_count && req_len)
	{
		if (req_len < 2 || req_len < 2 + *(request + 1))
			return ((void *)gets_crash(signup));
		if (*request == ID_TYPE && !signup->id_type)
			signup->id_type = *(request + 2);
		else if (!string_header(*request, signup, request + 2, *(request + 1)))
			return ((void *)gets_crash(signup));
		header_count--;
		req_len -= *(request + 1) + 2;
		request += *(request + 1) + 2;
	}
	if (header_count || req_len)
		return ((void *)gets_crash(signup));
	return ((void *)signup);
}
