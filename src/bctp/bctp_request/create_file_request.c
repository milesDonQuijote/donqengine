#include "bctp_request.h"

#define REQ_LEN 28 //request len without header values
#define HEADER_COUNT 7
#define ID_TYPE_LEN 1
#define FILE_SIZE_LEN 8
#define PEACE_COUNT 4

t_request_buf
create_file_request(t_file *req)
{
	char		*request;
	unsigned int	index;
	unsigned int	req_len, id_len, key_len, ff_len, toid_len;

	if (!req)
		return ((t_request_buf){0, 0});
	index = 0;
	id_len = ft_strlen(req->id);
	toid_len = ft_strlen(req->to_id);
	key_len = ft_strlen(req->key);
	ff_len = ft_strlen(req->file_format);
	req_len = REQ_LEN + id_len + toid_len + key_len + ff_len;

	request = (char *)malloc(sizeof(char) * req_len);
	if (!request)
		return ((t_request_buf){0, 0});
	request[index++] = FILE_TRANSFER;
	request[index++] = HEADER_COUNT;
	
	request[index++] = ID_TYPE;
	request[index++] = ID_TYPE_LEN;
	request[index++] = req->id_type;

	request[index++] = ID;
	request[index++] = (char)id_len;
	ft_strcpy(request + index, req->id);
	index += id_len;

	request[index++] = TO_ID;
	request[index++] = (char)toid_len;
	ft_strcpy(request + index, req->to_id);
	index += toid_len;

	request[index++] = KEY;
	request[index++] = (char)key_len;
	ft_strcpy(request + index, req->key);
	index += key_len;

	request[index++] = FILE_FORMAT;
	request[index++] = (char)ff_len;
	ft_strcpy(request + index, req->file_format);
	index += ff_len;

	*(unsigned int *)(request + index) = req->file_size;
	index += sizeof(unsigned int);

	*(int *)(request + index) = req->peace_count;
	index += sizeof(int);

	if (index == req_len)
		return ((t_request_buf){request, index});
	free(request);
	return ((t_request_buf){0, 0});
}
