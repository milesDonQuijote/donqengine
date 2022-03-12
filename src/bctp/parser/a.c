#include <stdio.h>
#include <stdlib.h>

typedef void *(*func)(char **);

void	*p(char **s)
{
	printf("p");
}

void	*s(char **s)
{
	printf("suka");
}

int	main()
{
	char	**st;
	func	f[2] = {&p, &s};
	(f[0])(st);
	(f[1])(st);
	return (0);
}
