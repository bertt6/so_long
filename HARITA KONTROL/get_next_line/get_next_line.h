/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamli <bsamli@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:50:52 by bsamli            #+#    #+#             */
/*   Updated: 2022/11/01 17:58:19 by bsamli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <unistd.h>

int		ft_strlen(char *c);
int		ft_find(char *finder);
char	*ft_line(char *handle_string);
char	*ft_clean(char *handle_string);
char	*ft_read(int fd, char *str);
char	*get_next_line(int fd);
char	*ft_strjoin(char *lft_str, char *buff);

#endif
