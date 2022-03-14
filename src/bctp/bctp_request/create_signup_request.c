#include "bctp_request.h"

#define REQ_LEN 13 //request len without id, password, name, and surname values
#define HEADER_COUNT 5
#define ID_TYPE_LEN 1;

t_request_buf
create_signup_request(t_signup *req)
{
	char		*request;
	unsigned int	index;
	unsigned int	req_len, id_len, psw_len, name_len, sname_len;

	if (!req)
		return ((t_request_buf){0, 0});
	index = 0;
	id_len = ft_strlen(req->id);
	psw_len = ft_strlen(req->password);
	name_len = ft_strlen(req->name);
	sname_len = ft_strlen(req->surname);
	req_len = REQ_LEN + id_len + psw_len + name_len + s_name_len;
	
	request = (char *)malloc(sizeof(char) * req_len);
	if (!request)
		return ((t_request_buf){0, 0});

	request[index++] = SIGNUP;			//request type
	request[index++] = HEDAER_COUNT;
	
	request[index++] = ID_TYPE;
	request[index++] = ID_TYPE_LEN;
	request[index++] = req->id_type;
	
	request[index++] = ID;
	request[index++] = (char)id_len;
	ft_strcpy(request + index, req->id);	//copy id to request from last index
	index += id_len;
	
	request[index++] = PASSWORD;
	request[index++] = (char)psw_len;
	ft_strcpy(request + index, req->password);
	index += psw_len;
	
	request[index++] = NAME;
	request[index++] = (char)name_len;
	ft_strcpy(request + index, req->name);
	index += name_len;
	
	request[index++] = SURNAME;
	request[index++] = sname_len;
	ft_strcpy(request + index, req->surname);
	index += sname_len;
	
	if (index == req_len)
		return ((t_request_buf){request, index});
	free(request);
	return ((t_request_buf){0, 0})
}
