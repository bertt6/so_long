/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapread.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamli <bsamli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 01:40:43 by macos             #+#    #+#             */
/*   Updated: 2023/01/19 16:45:54 by bsamli           ###   ########.fr       */
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

char	*ft_strjoin(char *left_str, char buff)
{
	int		i;
	char	*str;

	i = 0;
	while (left_str[i])
			i++;
	str = malloc(i + 2);
	i = 0;
	while (left_str[i])
	{
		str[i] = left_str[i];
		i++;
	}
	str[i] = buff;
	str[i + 1] = '\0';
	free(left_str);
	return (str);
}

int	ft_line_control(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\0')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_read(int fd)
{
	char	buffer;
	int		rd_bytes;
	char	*line;

	line = malloc(1);
	line[0] = '\0';
	rd_bytes = 1;
	while (rd_bytes > 0 && !ft_line_control(line))
	{
		rd_bytes = read(fd, &buffer, 1);
		if (rd_bytes == 0)
			return (line);
		line = ft_strjoin(line, buffer);
	}
	return (line);
}
