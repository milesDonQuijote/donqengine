#ifndef PARSER_H
# define PARSER_H

#include "../bctp.h"

typedef void *(*reqtype_func)(char *, unsigned int);

void	*get_signup(char *req, unsigned int req_len);
void	*get_signin(char *req, unsigned int req_len);
void	*get_signout(char *req, unsigned int req_len);

#endif
