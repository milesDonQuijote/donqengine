#include "parser.h"

static int	string_header(char header, t_file *s, char *value, unsigned int value_len)
{
	if (header == ID && !s->id)
		s->id = ft_substr(value, 0, value_len);
	else if (header == KEY && !s->key)
		s->key = ft_substr(value, 0, value_len);
	else if (header == TO_ID && !s->to_id)
		s->to_id = ft_substr(value, 0, value_len);
	else if (header == FILE_FORMAT && !s->file_format)
		s->file_format = ft_substr(value, 0, value_len);
	else
		return (0);
	return (1);
}

void	*get_file(char *request, unsigned int req_len)
{
	t_file		*file;
	unsigned int	header_count;
	
	if (req_len < 2)
		return ((void *)0);
	request++;
	req_len -= 2;
	header_count = (unsigned int)*request++;
	file = (t_file *)malloc(sizeof(t_file));
	if (!file)
		return ((void *)0);
	*file = (t_file){0, 0, 0, 0, 0, 0};
	while (header_count && req_len)
	{
		if (req_len < 2 || req_len < 2 + *(request + 1))
			return ((void *)gets_crash(file));
		if (*request == ID_TYPE && !file->id_type)
			file->id_type = *(request + 2);
		else if (*request == FILE_SIZE && !file->file_size)
			file->file_size = *(unsigned int *)(request + 2);
		else if (!string_header(*request, file, request + 2, *(request + 1)))
			return ((void *)gets_crash(file));
		header_count--;
		req_len -= *(request + 1) + 2;
		request += *(request + 1) + 2;
	}
	if (header_count || req_len)
		return ((void *)gets_crash(file));
	return ((void *)file);
}
