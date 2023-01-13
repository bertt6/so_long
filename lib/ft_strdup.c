#include "../so_long.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*src;

	i = 0;
	src = malloc(sizeof(*s1) * (ft_strlen(s1) + 1));
	if (!src)
		return (NULL);
	while (s1[i])
	{
		src[i] = s1[i];
		i++;
	}
	src[i] = '\0';
	return (src);
}