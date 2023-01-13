/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapread.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macos <macos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 01:40:43 by macos             #+#    #+#             */
/*   Updated: 2023/01/14 01:48:15 by macos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*d;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1)
	{
		d = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
		if (!d)
			return (NULL);
		while (s1[i] != '\0')
		{
			d[i] = s1[i];
			i++;
		}
		while (s2[j] != '\0')
		{
			d[i++] = s2[j];
			j++;
		}
		d[i] = '\0';
		return (d);
	}
	return (0);
}

char	*ft_read(int fd)
{
	char	*buff;
	char	*str;
	int 	rd_byte;

	buff = malloc(1 * sizeof(char));
	str = malloc(1);
	if (!buff)
		return (0);
	rd_byte = 1;
	while (rd_byte != 0)
	{
		rd_byte = read(fd, buff, 10);
		if (rd_byte == -1)
		{
			free(buff);
			return (0);
		}
		buff[rd_byte] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}
