#ifndef BCTP_REQUEST_H
# define BCTP_REQUEST_H

# include "../bctp.h"
# include "../../string/strings.h"
# include <stdlib.h>

typedef struct	s_request_buf {
	char		*buf;
	unsigned int	len;
}	t_request_buf;

t_request_buf
create_signup_request(t_signup *req);

t_request_buf
create_signin_request(t_signin *req);

t_request_buf
create_signout_request(t_signout *req);

t_request_buf
create_message_request(t_message *req);

t_request_buf
create_file_request(t_file *req);

t_request_buf
create_fstream_request(t_file_stream *req);

static inline t_request_buf
create_fstream_end_request()
{
	char	req = FILE_STREAM_END;
	return ((t_request_buf){ft_strncpy((char *)malloc(sizeof(char)), &req, 1)});
}
#endif
