void
*ft_memcpy(void *dst, void *src, unsigned int len)
{
	char	*src_buf;
	char	*dst_buf;

	src_buf = (char *)src;
	dst_buf = (char *)dst;

	if (!dst || !src)
		return ((void *))
	while (len--)
		*dst_buf++ = *src_buf++;
	return (dst);
}
