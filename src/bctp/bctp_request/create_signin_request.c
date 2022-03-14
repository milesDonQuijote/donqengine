#include "bctp_request.h"

#define REQ_LEN 9 //request len without id and password values
#define HEADER_COUNT 3
#define ID_TYPE_LEN 1

t_request_buf
create_signin_request(t_signin *req)
{
	char		*request;
	unsigned int	index;
	unsigned int	req_len, id_len, psw_len;

	if (!req)
		return ((t_request_buf){0, 0});
	index = 0;
	id_len = ft_strlen(req->id);
	psw_len = ft_strlen(req->password);
	req_len = REQ_LEN + id_len + psw_len;

	request = (char *)malloc(sizeof(char) * req_len);
	if (!request)
		return ((t_requst_buf){0, 0});
	
	request[index++] = SIGNIN;		//request type
	request[index++] = HEADER_COUNT;
	
	request[index++] = ID_TYPE;
	request[index++] = ID_TYPE_LEN;
	request[index++] = req->id_type;

	request[index++] = ID;
	request[index++] = (char)id_len;
	ft_strcpy(request + index, req->id);	//copyt id to req from last index
	index += id_len;

	request[index++] = PASSWORD;
	request[index++] = psw_len;
	ft_strcpy(request + index, req->password);
	index += psw_len;
	
	if (index == req_len)
		return ((t_request_buf){request, index});
	free(request);
	return ((t_request_buf){0, 0});
}
