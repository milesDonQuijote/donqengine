#include "strings.h"

char	*ft_substr(char *s, unsigned int start, unsigned int len)
{
	char		*result;
	unsigned int	idx;

	if (!s)
		return ((char *)0);
	result = (char *)malloc(sizeof(char) * (len + 1));
	while (len--)
		result[idx++] = s[start++];
	result[idx] = 0;
	return (result);
}
