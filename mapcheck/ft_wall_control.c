/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wall_control.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macos <macos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 20:14:13 by macos             #+#    #+#             */
/*   Updated: 2023/01/14 01:49:41 by macos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	top_left_wall_control(t_data *game)
{
	int	i;

	i = 0;
	while (i < game->mat_y)
	{
		if (game->map[i][0] != '1')
		{
			ft_printf("sol duvarlar hatalı");
			exit(1);
		}
		i++;
	}
	i = 0;
	while (i < game->mat_x)
	{
		if (game->map[0][i] != '1')
		{
			ft_printf("üst duvarlar hatalı");
			exit(1);
		}
		i++;
	}
}

void	right_bottom_wall_control(t_data *game)
{
	int	i;

	i = 0;
	while (i < game->mat_y)
	{
		if (game->map[i][game->mat_x - 1] != '1')
		{
			ft_printf("sağ duvarlar hatalı");
			exit(1);
		}
		i++;
	}
	i = 0;
	while (i < game->mat_x)
	{
		if (game->map[game->mat_y - 1][i] != '1')
		{
			ft_printf("alt duvarlar hatalı");
			exit(1);
		}
		i++;
	}
}

void	playable_control(t_data *game)
{
	if (game->collectnum < 1 || game->exit != 1)
	{
		ft_printf("Oynanılabilir değil");
		exit(1);
	}
}
