char
*ft_strncpy(char *dst, char *src, unsigned int len)
{
	char	*tmp;

	tmp = dst;
	if (!dst || !src)
		return (0);
	while (len-- && *src)
		*dst++ = *src++;
	return (tmp);
}

