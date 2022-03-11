#include "../hcptypes.h"
#include "hcpparser.h"

static int	compare(char **s1, char *s2)
{
	int	idx;

	if (!s1 || !*s1 || !s2)
		return (0);
	idx = 0;
	while ((*s1)[idx] && (*s1)[idx] == s2[idx])
		idx++;
	idx = idx * ((*s1)[idx] == '\n');
	*s1 += idx + (idx != 0);
	return (idx);
}

int	get_reqtype(char **str)
{
	if (compare(str, "signin"))
		return (SIGNIN);
	if (compare(str, "signup"))
		return (SIGNUP);
	if (compare(str, "signout"))
		return (SIGNOUT);
	return (-1);
}
