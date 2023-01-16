/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamli <bsamli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 01:40:22 by macos             #+#    #+#             */
/*   Updated: 2023/01/16 13:33:03 by bsamli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_read(int fd)
{
	char	*buff;
	char	*str;
	int		rd_byte;

	buff = malloc (1 * sizeof(char));
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
