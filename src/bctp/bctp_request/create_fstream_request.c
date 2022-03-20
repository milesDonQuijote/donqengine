#include "bctp_request.h"

#define REQ_LEN 8
#define HEADER_COUNT 2

t_request_buf
create_fstream_request(t_file_stream *req)
{
	char		*request;
	unsigned int	index;
	unsigned int	req_len, key_len, fkey_len, fragment_len;

	if (!req)
		return ((t_request_buf){0, 0});
	index = 0;
	key_len = ft_strlen(req->key);
	fkey_len = ft_strlen(req->fkey);
	fragment_len = ft_strlen(req->fragment);
	req_len = REQ_LEN + key_len + fkey_len, fragment_len;

	request = (char *)malloc(sizeof(char) * req_len);
	if (!request)
		return ((t_request_buf){0, 0});
	request[index++] = FILE_STREAM;
	request[index++] = HEADER_COUNT;
	
	request[index++] = KEY;
	request[index++] = key_len;
	ft_strcpy(request + index, req->key);
	index += key_len;
	
	request[index++] = FKEY;
	request[index++] = fkey_len;
	ft_strcpy(request + index, req->fkey);
	index += fkey_len;

	*(int *)(request + index) = req->fragment_num;
	index += sizeof(int);

	*(unsigned int *)(request + index) = req->fragment_len;
	index += sizeof(unsigned int);

	ft_strcpy(request + index, req->fragment);
	index += fragment_len;

	if (index == req_len)
		return ((t_request_buf){request, index});
	free(request);
	return ((t_request_buf){0, 0});

}
