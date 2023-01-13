/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macos <macos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 01:39:16 by macos             #+#    #+#             */
/*   Updated: 2023/01/14 01:39:46 by macos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_up(t_data *game)
{
	if (game->map[game->position_y - 1][game->position_x] == 'C')
		game->coin--;
	game->map[game->position_y][game->position_x] = '0';
	game->map[game->position_y - 1][game->position_x] = 'P';
	game->position_y--;
	mlx_put_image_to_window(game->mlx, game->mlx_window, game->img[4],
		game->position_x, game->position_y);
	game->step++;
}

void	ft_move_down(t_data *game)
{
	if (game->map[game->position_y + 1][game->position_x] == 'C')
		game->coin--;
	game->map[game->position_y][game->position_x] = '0';
	game->map[game->position_y + 1][game->position_x] = 'P';
	game->position_y++;
	mlx_put_image_to_window(game->mlx, game->mlx_window, game->img[4],
		game->position_x, game->position_y);
	game->step++;
}

void	ft_move_left(t_data *game)
{
	if (game->map[game->position_y][game->position_x - 1] == 'C')
		game->coin--;
	game->map[game->position_y][game->position_x] = '0';
	game->map[game->position_y][game->position_x - 1] = 'P';
	game->step++;
	game->position_x--;
	mlx_put_image_to_window(game->mlx, game->mlx_window, game->img[4],
		game->position_x, game->position_y);
}

void	ft_move_right(t_data *game)
{
	if (game->map[game->position_y][game->position_x + 1] == 'C')
		game->coin--;
	game->map[game->position_y][game->position_x] = '0';
	game->map[game->position_y][game->position_x + 1] = 'P';
	game->step++;
	game->position_x++;
	mlx_put_image_to_window(game->mlx, game->mlx_window, game->img[4],
		game->position_x, game->position_y);
}
