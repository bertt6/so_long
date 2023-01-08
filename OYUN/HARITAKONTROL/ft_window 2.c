#include "../so_long.h"

void	ft_window(t_data *data)
{
	ft_collect(data);
	data->mlx = mlx_init();
    printf("%d, %d\n", data->width, data->height);
    data->mlx_window = mlx_new_window(data->mlx, data->width * 64, 
    data->height * 64, "SO_LONG");
    data->img[0] = mlx_xpm_file_to_image(data->mlx, PL_FT,
        &data->imgx, &data->imgy);
    data->img[1] = mlx_xpm_file_to_image(data->mlx, PL_LT,
        &data->imgx, &data->imgy);
    data->img[2] = mlx_xpm_file_to_image(data->mlx, PL_RT,
        &data->imgx, &data->imgy);
    data->img[3] = mlx_xpm_file_to_image(data->mlx, PL_BC,
            &data->imgx, &data->imgy);
        data->img[4] = mlx_xpm_file_to_image(data->mlx, GR,
            &data->imgx, &data->imgy);
    data->img[5] = mlx_xpm_file_to_image(data->mlx, WLL, 
            &data->imgx, &data->imgy);
    data->img[6] = mlx_xpm_file_to_image(data->mlx, COIN, 
            &data->imgx, &data->imgy);
    data->img[7] = mlx_xpm_file_to_image(data->mlx, DOR, 
            &data->imgx, &data->imgy);
	ft_res(data);
}

void	ft_res(t_data *game)
{
	char	*walkcount;

	game->mat_x = 0;
	game->mat_x = 0;
	ft_win(game);
	mlx_hook(game->mlx_window, 2, 0, ft_key, game);
	mlx_string_put(game->mlx, game->mlx_window, 20, 30, 0xFF0000, "Walk Count:");
	walkcount = ft_itoa(game->step);
	mlx_string_put(game->mlx, game->mlx_window, 110, 30, 0xFF0000, walkcount);
	free(walkcount);
	printf("Walk Count: %d\n", game->step);
	mlx_loop(game->mlx);
}

void	ft_win(t_data *game)
{
	mlx_clear_window(game->mlx, game->mlx_window);
	while (game->controlmap[game->mat_y])
	{
		game->mat_x = 0;
		while (game->controlmap[game->mat_x][game->mat_x])
		{
			if (game->controlmap[game->mat_y][game->mat_x] == '1')
				mlx_put_image_to_window(game->mlx, game->mlx_window, \
					game->wallptr, game->mat_x * 64, game->mat_y * 64);
			if (game->controlmap[game->mat_y][game->mat_x] == 'P')
				mlx_put_image_to_window(game->mlx, game->mlx_window, \
					game->playerptr, game->mat_x * 64, game->mat_y * 64);
			if (game->controlmap[game->mat_y][game->mat_x] == 'C')
				mlx_put_image_to_window(game->mlx, game->mlx_window, \
					game->coinptr, game->mat_x * 64, game->mat_y * 64);
			if (game->controlmap[game->mat_y][game->mat_x] == 'E')
				mlx_put_image_to_window(game->mlx, game->mlx_window, \
					game->exittptr, game->mat_x * 64, game->mat_y * 64);
			else if (game->controlmap[game->mat_y][game->mat_x] == '0')
				mlx_put_image_to_window(game->mlx, game->mlx_window, \
					game->emptyptr, game->mat_x * 64, game->mat_y * 64);
			game->mat_x ++;
		}
		game->mat_y++;
	}
}

int	ft_key(int keyhook, t_data *game)
{
	if (keyhook == 53)
		exit(1);
	if (game->collectnum == 0
		&& ((keyhook == 2 && \
		game->controlmap[game->position_y][game->position_x + 1] == 'E')
		|| (keyhook == 1 && \
		game->controlmap[game->position_y + 1][game->position_x] == 'E')
		|| (keyhook == 0 && \
		game->controlmap[game->position_y][game->position_x - 1] == 'E')
		|| (keyhook == 13 && \
		game->controlmap[game->position_y - 1][game->position_x] == 'E')))
	{
		printf("Walk Count: %d\n", game->step + 1);
		printf("Game Over!! YOU WON!!\n");
		exit(1);
	}
	ft_key_hook(keyhook, game);
	ft_res(game);
	return (0);
}

void	ft_key_hook(int keyhook, t_data *game)
{
	if (keyhook == 13 && \
		game->controlmap[game->position_y - 1][game->position_x] != '1'
		&& game->controlmap[game->position_y - 1][game->position_x] != 'E')
		ft_move_up(game);
	if (keyhook == 0 && game->controlmap[game->position_y][game->position_x - 1] != '1'
		&& game->controlmap[game->position_y][game->position_x - 1] != 'E')
		ft_move_left(game);
	if (keyhook == 1 && game->controlmap[game->position_y + 1][game->position_x] != '1'
		&& game->controlmap[game->position_y + 1][game->position_x] != 'E')
		ft_move_down(game);
	if (keyhook == 2 && game->controlmap[game->position_y][game->position_x + 1] != '1'
		&& game->controlmap[game->position_y][game->position_x + 1] != 'E')
		ft_move_right(game);
}

void	ft_collect(t_data *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (game->controlmap[y][x])
		{
			if (game->controlmap[y][x] == 'C')
				game->collectnum++;
			x++;
		}
		y++;
	}
}