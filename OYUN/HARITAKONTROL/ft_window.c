#include "../so_long.h"

void ft_window(t_data *data)
{
    data->mlx = mlx_init();
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

    hookles(data);
}

void hookles(t_data *data)
{
    char *step;

    data->mat_x = 0;
    data->mat_y = 0;
    step = ft_itoa(data->step);
    ft_putimages(data);
    mlx_hook(data->mlx_window, 3, 0, ft_keyboard, data);
    mlx_hook(data->mlx_window, 4, 0, mouse, data);
    //mlx_loop_hook(data->mlx, *ft_update, data);
    mlx_string_put(data->mlx, data->mlx_window, 10, 20, 0x00FF00, "Step :");
    mlx_string_put(data->mlx, data->mlx_window, 80, 20, 0x00FF00, step);
    mlx_loop(data->mlx);
}

void	ft_putimages(t_data *game)
{
	

	game->coin = 0;
	mlx_clear_window(game->mlx, game->mlx_window);
	while (game->controlmap[game->mat_y])
	{
		game->mat_x = 0;
		while (game->controlmap[game->mat_y][game->mat_x])
		{
			mlx_put_image_to_window(game->mlx, game->mlx_window, game->img[4], game->mat_x * 64, game->mat_y * 64);
			if (game->controlmap[game->mat_y][game->mat_x] == '1')
                mlx_put_image_to_window(game->mlx, game->mlx_window, game->img[5], game->mat_x * 64, game->mat_y * 64);
			if (game->controlmap[game->mat_y][game->mat_x] == 'P')
			{
                mlx_put_image_to_window(game->mlx, game->mlx_window, game->img[0], game->mat_x * 64, game->mat_y * 64);
				game->position_x = game->mat_x;
				game->position_y = game->mat_y;
			}				
			if (game->controlmap[game->mat_y][game->mat_x] == 'C')
			{
				mlx_put_image_to_window(game->mlx, game->mlx_window, game->img[6], game->mat_x * 64, game->mat_y * 64);
				game->coin++;
			}
			if (game->controlmap[game->mat_y][game->mat_x] == 'E')
                mlx_put_image_to_window(game->mlx, game->mlx_window, game->img[7], game->mat_x * 64, game->mat_y * 64);
			if (game->controlmap[game->mat_y][game->mat_x] == '0')
				mlx_put_image_to_window(game->mlx, game->mlx_window, game->img[4], game->mat_x * 64, game->mat_y * 64);

			game->mat_x ++;
		}
		game->mat_y++;
	}
	can_go_exit(game);
}

void can_go_exit(t_data *data)
{
	char *coin;
	static int i;

	i = 1;
	printf("\nCOINS : %d\n", data->coin);
	coin = ft_itoa(data->coin);
	mlx_string_put(data->mlx, data->mlx_window, 10, 50, 0x00FF00, "COIN : ");
	mlx_string_put(data->mlx, data->mlx_window, 80, 50, 0x00FF00, coin);
	if(data->coin == 0)
	{
		mlx_string_put(data->mlx, data->mlx_window, 10, 82, 0xFFFFFF, "KAPIYA GIDEBILIRSIN!");
	}
}

void	ft_key_hook(int keyhook, t_data *game)
{
	if (keyhook == 13 && \
		game->controlmap[game->position_y - 1][game->position_y] != '1'
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

int	ft_keyboard(int keyhook, t_data *game)
{
	if (keyhook == 53)
        exit(1);
	if (game->coin == 0
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
	hookles(game);
	return (0);
}