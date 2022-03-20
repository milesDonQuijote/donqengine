#ifndef STRINGS_H
# define STRINGS_H

#include <stdlib.h>

char
*ft_substr(char *s, unsigned int start, unsigned int len);

char		
*ft_strcpy(char *dst, char *src);

char
*ft_strncpy(char *dst, char *src, unsigned int len);

unsigned int
ft_strlen(char *str);

void
*ft_memcpy(void *dst, void *src, unsigned int len);
#endif
