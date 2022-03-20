#include "bctp_response.h"

#define REQ_LEN 1

t_response_buf
create_fstream_success_response(unsigned int len)
{
	unsigned int	index, req_len;
	char		*response;

	req_len = REQ_LEN + sizeof(len);
	response = (char *)malloc(sizeof(char) * req_len);
	if (!response)
		return ((t_response_buf){0, 0});
	index = 0;
	request[index++] = FSTREAM_SUCCESS;
	*(unsigned int)(request + index) = len;
	index += sizeof(len);

	if (index == req_len)
		return ((t_response_buf){response, index});
	return ((t_response_buf){0, 0});
}
