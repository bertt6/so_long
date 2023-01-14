/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapread.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamli <bsamli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 01:40:43 by macos             #+#    #+#             */
/*   Updated: 2023/01/14 15:11:47 by bsamli           ###   ########.fr       */
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

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	char	*newstr;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	j = 0;
	i = 0;
	newstr = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (!newstr)
		return (NULL);
	while (s1[i])
	{
		newstr[j++] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		newstr[j++] = s2[i];
		i++;
	}	
	newstr[j] = '\0';
	return (newstr);
}//freelenecek

char	*ft_read(int fd)
{
	char	*buff;
	char	*str;
	int		rd_byte;

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
