/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamli <bsamli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 01:39:16 by macos             #+#    #+#             */
/*   Updated: 2023/01/19 16:49:59 by bsamli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_up(t_data *data)
{
	if (data->map[data->position_y - 1][data->position_x] == 'C')
		data->coin--;
	data->map[data->position_y][data->position_x] = '0';
	data->map[data->position_y - 1][data->position_x] = 'P';
	data->position_y--;
	mlx_put_image_to_window(data->mlx, data->mlx_window, data->img[4],
		data->position_x, data->position_y);
	data->step++;
}

void	ft_move_down(t_data *data)
{
	if (data->map[data->position_y + 1][data->position_x] == 'C')
		data->coin--;
	data->map[data->position_y][data->position_x] = '0';
	data->map[data->position_y + 1][data->position_x] = 'P';
	data->position_y++;
	mlx_put_image_to_window(data->mlx, data->mlx_window, data->img[4],
		data->position_x, data->position_y);
	data->step++;
}

void	ft_move_left(t_data *data)
{
	if (data->map[data->position_y][data->position_x - 1] == 'C')
		data->coin--;
	data->map[data->position_y][data->position_x] = '0';
	data->map[data->position_y][data->position_x - 1] = 'P';
	data->step++;
	data->position_x--;
	mlx_put_image_to_window(data->mlx, data->mlx_window, data->img[4],
		data->position_x, data->position_y);
}

void	ft_move_right(t_data *data)
{
	if (data->map[data->position_y][data->position_x + 1] == 'C')
		data->coin--;
	data->map[data->position_y][data->position_x] = '0';
	data->map[data->position_y][data->position_x + 1] = 'P';
	data->step++;
	data->position_x++;
	mlx_put_image_to_window(data->mlx, data->mlx_window, data->img[4],
		data->position_x, data->position_y);
}

void map_is_space(t_data *data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(data->map[i])
	{
		if(data->map[i][0] == '\n')
		{
			ft_printf("Found space!");
			exit(1);		
		}
		i++;
	}
}
