#include "bctp.h"
#include "bctp_request/bctp_request.h"
#include "parser/parser.h"
#include <unistd.h>

int	main()
{
	t_request	req;
	t_message	msg;
	t_message	*m;
	t_request_buf	buf;

	msg.id = "";
	msg.key = "";
	msg.to_id = "";
	msg.file_format = ".jpg";
	msg.content_len = 1;
	msg.content = "a";

	write(1, "before\n",7);
	buf = create_message_request(&msg);
	write(1, "after\n", 6);
	req = parse_bctp(buf.buf, buf.len);
	write(1, "after\n", 6);
	m = (t_message *)req.data;
	write(1, "after\n", 6);

	if (m)
		printf("%i\n", m->content_len);
}
