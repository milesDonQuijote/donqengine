#ifndef PARSER_H
# define PARSER_H

#include "../bctp.h"
# include "../../string/strings.h"

typedef void *(*t_reqtype_func)(char *, unsigned int);

t_request	parse_bctp(void *request, unsigned int req_len);

void	*get_signup(char *req, unsigned int req_len);
void	*get_signin(char *req, unsigned int req_len);
void	*get_signout(char *req, unsigned int req_len);
void	*get_message(char *req, unsigned int req_len);

static inline void	*gets_crash(void *mem)
{
	free(mem);
	return ((void *)0);
}

#endif
