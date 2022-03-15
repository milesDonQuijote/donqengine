#include "bctp_request.h"

#define REQ_LEN 20 //request len without header values
#define	HEADER_COUNT 6
#define ID_TYPE_LEN 1;
#define MSG_TYPE_LEN 1;

t_request_buf
create_message_request(t_message *req)
{
	char		*request;
	unsigned int	index;
	unsigned int	req_len, id_len, key_len, toid_len, frm_len;

	if (!req)
		return ((t_request_buf){0, 0});
	index = 0;
	id_len = ft_strlen(req->id);
	key_len = ft_strlen(req->key);
	toid_len = ft_strlen(req->to_id);
	frm_len = ft_strlen(req->file_format);
	req_len = REQ_LEN + id_len + key_len + toid_len + frm_len + req->content_len;

	request = (char *)malloc(sizeof(char) * req_len);
	if (!request)
		return ((t_request_buf){0, 0});

	request[index++] = MESSAGE;			//request type
	request[index++] = HEADER_COUNT;

	request[index++] = MESSAGE_TYPE;
	request[index++] = MSG_TYPE_LEN;
	request[index++] = req->msg_type;

	request[index++] = ID_TYPE;
	request[index++] = ID_TYPE_LEN;
	request[index++] = req->id_type;

	request[index++] = ID;
	request[index++] = (char)id_len;
	ft_strcpy(request + index, req->id);	//copy id to request from last index
	index += id_len;

	request[index++] = KEY;
	request[index++] = (char)key_len;
	ft_strcpy(request + index, req->key);
	index += key_len;

	request[index++] = TO_ID;
	request[index++] = (char)toid_len;
	ft_strcpy(request + index, req->to_id);
	index += toid_len;

	request[index++] = FILE_FORMAT;
	request[index++] = (char)frm_len;
	ft_strcpy(request + index, req->file_format);
	index += frm_len;

	*(int *)(request + index) = (int)req->content_len;
	index += sizeof(int);
	ft_memcpy(request + index, req->content, req->content_len);
	index += req->content_len;

	if (index == req_len)
		return ((t_request_buf){request, index});
	free(request);
	return ((t_request_buf){0, 0});
}
