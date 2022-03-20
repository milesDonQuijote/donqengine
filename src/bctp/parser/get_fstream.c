#include "parser.h"

static inline int	string_header(char header, t_file_stream *s, char *value, unsigned int value_len)
{
	if (header == KEY && !s->key)
		s->key = ft_substr(value, 0, value_len);
	else if (header == FKEY && !s->fkey)
		s->fkey = ft_substr(value, 0, value_len);
	else
		return (0);
	return (1);
}

void	*get_fstream(char *request, unsigned int req_len)
{
	t_file_stream	*fstream;
	unsigned int	header_count;
	unsigned int	fragment_len;

	if (req_len < 2)
		return ((void *)0);
	request++;
	req_len -= 2;
	header_count = (unsigned int)*request++;
	fstream = (t_file_stream *)malloc(sizeof(t_file_stream));
	if (!fstream)
		return ((void *)0);
	*fstream = (t_file_stream){0, 0, 0, 0, 0};
	while (header_count && req_len)
	{
		if (req_len < 2 || req_len < 2 + *(request + 1))
			return ((void *)gets_crash(fstream));
		if (!string_header(*request, fstream, request + 2, *(request + 1)))
			return ((void *)gets_crash(fstream));
		header_count--;
		req_len -= *(request + 1) + 2;
		request += *(request + 1) + 2;
	}
	if (req_len < sizeof(int) + sizeof(unsigned int))
		return ((void *)0);
	fstream->fragment_num = *(int *)request;
	request += sizeof(int);
	fstream->fragment_len = *(unsigned int *)request;
	request += sizeof(unsigned int);
	req_len -= sizeof(int) + sizeof(unsigned int);
	if (req_len && fragment_len == req_len)
	{
		fstream->fragment = ft_substr(request, 0, fstream->fragment_len);
		req_len -= fstream->fragment_len;
	}
	if (header_count || req_len)
		return ((void *)gets_crash(fstream));
	return ((void *)fstream);
}
