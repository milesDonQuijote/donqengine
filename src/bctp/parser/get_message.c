#include "parser.h"

static inline int	string_header(char header, t_message *s, char *value, unsigned int value_len)
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

void	*get_message(char *request, unsigned int req_len)
{
	t_message	*msg;
	unsigned int	header_count;
	unsigned int	content_len;

	if (req_len < 2)
		return ((void *)0);
	request++;
	req_len -= 2;
	header_count = (unsigned int)*request++;
	msg = (t_message *)malloc(sizeof(t_message));
	if (!msg)
		return ((void *)0);
	*msg = (t_message){0, 0, 0, 0};
	while (header_count && req_len)
	{
		if (req_len < 2 || req_len < 2 + *(request + 1))
			return ((void *)gets_crash(msg));
		if (*request == ID_TYPE && !msg->id_type)
			msg->id_type = *(request + 2);
		else if (*request == MESSAGE_TYPE && !msg->msg_type)
			msg->msg_type = *(request + 2);
		else if (!string_header(*request, msg, request + 2, *(request + 1)))
			return ((void *)gets_crash(msg));
		header_count--;
		req_len -= *(request + 1) + 2;
		request += *(request + 1) + 2;
	}
	content_len = *(int *)request;
	request += sizeof(int);
	req_len -= sizeof(int);
	if (req_len && content_len == req_len)
	{
		msg->content_len = content_len;
		msg->content = ft_substr(request, 0, content_len);
		req_len -= content_len;
		content_len = 0;
	}
	if (header_count || req_len || content_len)
		return ((void *)gets_crash(msg));
	return ((void *)msg);
}
