#include "parser.h"

t_parsed_request	parse_bctp(void *request, unsigned int req_len)
{
	char		*req_c;
	t_reqtype_func	runreq[REQTYPES_LEN] = {&get_signup, &get_signin, &get_signout};

	req_c = (char *)request;
	if (*req_c > REQTYPES_LEN)
		return ((t_parsed_request){0, (void *)0});
	return ((t_parsed_request){(int)*req_c, (runreq[*req_c])(request, req_len)});
}
