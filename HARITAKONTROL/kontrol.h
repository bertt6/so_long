#ifndef KONTROL_H
# define KONTROL_H
#define N 4

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int     ft_safe(int i, int j, int matrix[][N]);
int     ft_path(int matrix[][N], int i, int j, int visited[][N]);
void    ft_path_find(int matrix[][N]);
size_t	ft_strlcpy(char *restrict dst, const char *restrict src, size_t dstsize);
char	*ft_substr(char	const *s, unsigned int start, size_t len);
int	    ftcount(char const *s, char c);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_read(int fd);


#endif