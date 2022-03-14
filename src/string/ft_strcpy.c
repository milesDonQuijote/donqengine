char
*ft_strcpy(char *dst, char *src)
{
	char	*tmp;

	tmp = dst;
	if (!dst || !src)
		return (0);
	while (*src)
		*dst++ = *src++;
	return (tmp);
}
