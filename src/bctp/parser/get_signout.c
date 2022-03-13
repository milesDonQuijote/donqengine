#include "parser.h"

void	*get_signout(char *request, unsigned int req_len)
{
        t_signout        *signout;
        unsigned int    header_count;

        if (req_len < 2)
                return ((void *)0);
        request++;
        req_len -= 2;
        header_count = (unsigned int)*request++;
        signout = (t_signout *)malloc(sizeof(t_signout));
        *signout = (t_signout){0, 0, 0};
        while (header_count && req_len)
        {
                if (req_len < 2 || req_len < 2 + *(request + 1)) {
                        free(signout);
                        return ((void *)0);
                }
                if (*request == ID_TYPE && !signout->id_type) {
                        request += 2;
                        signout->id_type = *request++;
                        req_len -= 3;
                }
                else if (*request == ID && !signout->id) {
                        if (req_len - 2 < (unsigned int)*(++request)) {
                                free(signout);
                                return ((void *)0);
                        }
                        signout->id = ft_substr(request, 1, (unsigned int)*request);
                        req_len -= 2 + *request;
                        request += *request + 1;
                }
                else if (*request == KEY && !signout->key) {
                        if (req_len - 2 < (unsigned int)*(++request)) {
				free(signout);
                                return ((void *)0);
                        }
                        signout->key = ft_substr(request, 1, (unsigned int)*request);
                        req_len -= 2 + *request;
                        request += *request + 1;
                }
                else {
                        free(signout);
                        return ((void *)0);
                }
                header_count--;
        }
        if (header_count || req_len) {
                free(signout);
                return ((void *)0);
        }
        return ((void *)signout);
}
