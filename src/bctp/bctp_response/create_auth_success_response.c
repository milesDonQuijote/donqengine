#include "bctp_response.h"

#define REQ_LEN 3

t_response_buf
create_auth_success_response(char *key)
{
	unsigned int	index, key_len, req_len;
	char		*response;

	key_len = ft_strlen(key);
	req_len = REQ_LEN + key_len;
	response = (char *)malloc(sizeof(char) * req_len);
	if (!response)
		return ((t_response_buf){0, 0});
	index = 0;
	response[index++] = AUTH_SUCCESS;
	response[index++] = KEY;
	response[index++] = (char)key_len;
	ft_strcpy(response + index, key);
	index += key_len;

	if (index == req_len)
		return ((t_response_buf){response, index});
	return ((t_response_buf){0, 0});
}
