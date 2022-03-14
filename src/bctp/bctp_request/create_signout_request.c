#include "bctp_request.h"

#define REQ_LEN 9 //request len without id and key value
#define HEADER_COUNT 3
#define ID_TYPE_LEN 1

t_request_buf
create_signout_request(t_signout *req)
{
	char		*request;
	unsigned int	index;
	unsigned int	req_len, id_len, key_len;

	if (!req)
		return ((t_request_buf){0, 0});
	index = 0;
	id_len = ft_strlen(req->id);
	key_len = ft_strlen(req->key);
	req_len = REQ_LEN + id_len + key_len;
	
	request = (char *)malloc(sizeof(char) * req_len);
	if (!request)
		return ((t_request_buf){0, 0});

	request[index++] = SIGNOUT;		//request type
	request[index++] = HEADER_COUNT;

	request[index++] = ID_TYPE;
	request[index++] = ID_TYPE_LEN;
	request[index++] = req->id_type;

	request[index++] = ID;
	request[index++] = id_len;
	ft_strcpy(request + index, req->id);	//copy id to request from last index
	index += id_len;

	request[index++] = KEY;
	request[index++] = key_len;
	ft_strcpy(request + index, req->key);
	index += key_len;

	if (index == req_len)
		return ((t_request_buf){request, index});
	free(request);
	return ((t_request_buf){0, 0});
}
