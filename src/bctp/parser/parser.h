#ifndef PARSER_H
# define PARSER_H

#include "../bctp.h"
# include "../../string/strings.h"

typedef void *(*t_reqtype_func)(char *, unsigned int);

void	*get_signup(char *req, unsigned int req_len);
void	*get_signin(char *req, unsigned int req_len);
void	*get_signout(char *req, unsigned int req_len);

void	*gets_crash(void *mem);

#endif
