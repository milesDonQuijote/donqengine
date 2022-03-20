#ifndef BCTP_RESPONSE_H
# define BCTP_RESPONSE_H

# include "../bctp.h"
# include "../../string.h"
# include <stdlib.h>

typedef struct	s_response_buf {
	char		*buf;
	unsigned int	len;
}

static inline t_response_buf
create_id_used_response() {
	char	req = ID_USED;
	return ((t_response_buf){ft_stnrcpy((char *)malloc(sizeof(char)), &req, 1), 1});
}

static inline t_response_buf
create_auth_failed_response() {
	char	req = AUTH_FAILED;
	return ((t_response_buf){ft_strncpy((char *)malloc(sizeof(char)), &req, 1), 1});
}

t_response_buf
create_auth_success_response(char *key);

static inline t_response_buf
create_file_failed_response() {
	char	req = FILE_FAILED;
	return ((t_response_buf){ft_strncpy((char *)malloc(sizeof(char)), &req, 1), 1});
}

t_response_buf
create_file_success_response(char *key);

static inline t_response_buf
create_dst_notfound_response() {
	char	req = DST_NOTFOUND;
	return ((t_response_buf){ft_strncpy((char *)malloc(sizeof(char)), &req, 1), 1});
}

static inline t_response_buf
create_dst_found_response() {
	char	req = DST_FOUND;
	return ((t_response_buf){ft_strncpy((char *)malloc(sizeof(char)), &req, 1), 1});
}

static inline t_response_buf
create_req_invalid_response() {
	char	req = REQ_INVALID;
	return ((t_response_buf){ft_strncpy((char *)malloc(sizeof(char)), &req, 1), 1});
}

#endif
