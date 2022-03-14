#include "parser.h"

static int	string_header(char header, t_signout *s, char *value, unsigned int value_len)
{
	if (header == ID && !s->id)
		s->id = ft_substr(value, 0, value_len);
	else if (header == KEY && !s->key)
		s->key = ft_substr(value, 0, value_len);
	else
		return (0);
	return (1);
}

void	*get_signout(char *request, unsigned int req_len)
{
        t_signout        *signout;
        unsigned int    header_count;

        if (req_len < 2)
                return ((void *)0);
        request++;
        req_len -= 2;
        header_count = (unsigned int)*request++;
        signout = (t_signout *)malloc(sizeof(t_signout));
        *signout = (t_signout){0, 0, 0};
        while (header_count && req_len)
        {
                if (req_len < 2 || req_len < 2 + *(request + 1))
                        return ((void *)gets_crash(signout));
                if (*request == ID_TYPE && !signout->id_type)
                        signout->id_type = *(request + 2);
                else if (!string_header(*request, signout, request + 2, *(request + 1)))
                        return ((void *)gets_crash(signout));
                header_count--;
		req_len -= *(request + 1) + 2;
		request += *(request + 1) + 2;
        }
        if (header_count || req_len)
                return ((void *)gets_crash(signout));
        return ((void *)signout);
}
