/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_general_control.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamli <bsamli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 01:40:41 by macos             #+#    #+#             */
/*   Updated: 2023/01/16 13:48:05 by bsamli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_argcheck(char *map[])
{
	int	i;
	int	j;

	j = 0;
	while (*map && map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if ((map[j][i] != 'P') && (map[j][i] != '0') && (map[j][i] != '1')
				&& (map[j][i] != 'E') && (map[j][i] != 'C')
				&& (map[j][i] != '\n'))
			{
				write(1, "Invalid Map!", 13);
				exit(1);
			}
			i++;
		}
		j++;
	}
	ft_printf("Valid map!\n");
}

void	exit_check(char *map[])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
			{
				ft_printf("\033[1;96m There is exit!\n");
				return ;
			}
			else
			{
				j++;
			}
		}
		i++;
	}
	ft_printf("There isn't exit");
	exit(1);
}
