/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekahram <sekahram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 20:14:13 by sekahram          #+#    #+#             */
/*   Updated: 2022/12/23 13:34:20 by sekahram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
void	ft_map_area_control_v2(t_data *game)
{
	if (BURAYA HARİTANIN ALANI GELİCEK != game->mat_x * game->mat_y)
	{
		printf("wrong map desing!!");
		exit(1);
	}
}
*/

void	top_left_wall_control(t_data *game)
{
	int	i;

	i = 0;
	while (i < game->mat_y)
	{
		if (game->map[i][0] != '1')
		{
			printf("sol duvarlar hatalı");
			exit(1);
		}
		i++;
	}
	i = 0;
	while (i < game->mat_x)
	{
		if (game->map[0][i] != '1')
		{
			printf("üst duvarlar hatalı");
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
			printf("sağ duvarlar hatalı");
			exit(1);
		}
		i++;
	}
	i = 0;
	while (i < game->mat_x)
	{
		if (game->map[game->mat_y - 1][i] != '1')
		{
			printf("alt duvarlar hatalı");
			exit(1);
		}
		i++;
	}
}

void	ft_player_find(t_data *game)
{
	while (game->position_y < game->mat_y)
	{
		while (game->position_x < game->mat_x)
		{
			if (game->map[game->position_y][game->position_x] == 'P')
			{
				ft_map_playable_control(game, game->position_x, game->position_y);
				playable_control(game);
				return ;
			}
			game->position_x++;
		}
		game->position_x = 0;
		game->position_y++;
	}
}

void	playable_control(t_data *game)
{
	if (game->collectnum > 0 || game->exit > 0)
	{
		printf("Oynanılabilir değil");
		exit(1);
	}
}
