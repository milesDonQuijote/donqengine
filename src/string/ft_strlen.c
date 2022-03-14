unsigned int	ft_strlen(char *str)
{
	char	*tmp;

	tmp = str;
	while (str && *str++)
		;
	return ((unsigned int)(str - tmp));
}
