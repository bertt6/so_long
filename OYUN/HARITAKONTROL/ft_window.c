#include "../so_long.h"

void ft_window(t_data *data)
{
    data->mlx = mlx_init();
    printf("%d, %d\n", data->width, data->height);
    data->mlx_window = mlx_new_window(data->mlx, data->width * 64, data->height * 64, "SO_LONG");
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
    data->img[5] = mlx_xpm_file_to_image(data->mlx, WLL, &data->imgx, &data->imgy);
    data->img[6] = mlx_xpm_file_to_image(data->mlx, COIN, &data->imgx, &data->imgy);
    data->img[7] = mlx_xpm_file_to_image(data->mlx, DOR, &data->imgx, &data->imgy);

    hookles(data);
}

void hookles(t_data *data)
{
    char *step;

    data->mat_x = 0;
    data->mat_y = 0;
    step = ft_itoa(data->step);
    ft_putimages(data);
    mlx_hook(data->mlx_window, 3, 0, key_event, data);
    mlx_hook(data->mlx_window, 4, 0, mouse, data);
    mlx_loop_hook(data->mlx, *ft_update, data);
    mlx_string_put(data->mlx, data->mlx_window, 10, 20, 0x00FF00, "Step :");
    mlx_string_put(data->mlx, data->mlx_window, 80, 20, 0x00FF00, step);
    mlx_loop(data->mlx);
}

void ft_putimages(t_data *data)
{
    mlx_clear_window(data->mlx, data->mlx_window);
    while(data->controlmap[data->mat_y])
    {
        data->mat_x = 0;
        while(data->controlmap[data->mat_y][data->mat_x])
        {
            if(data->controlmap[data->mat_y][data->mat_x] == '1')
                mlx_put_image_to_window(data->mlx, data->mlx_window, data->img[5], data->mat_x * 64, data->mat_y * 64);
            else if(data->controlmap[data->mat_y][data->mat_x] == '0')
                mlx_put_image_to_window(data->mlx, data->mlx_window, data->img[4], data->mat_x * 64, data->mat_y * 64);
            else if(data->controlmap[data->mat_y][data->mat_x] == 'P')
                mlx_put_image_to_window(data->mlx, data->mlx_window, data->img[0], data->mat_x * 64, data->mat_y * 64);
            else if(data->controlmap[data->mat_y][data->mat_x] == 'C')
                mlx_put_image_to_window(data->mlx, data->mlx_window, data->img[6], data->mat_x * 64, data->mat_y * 64);
            else if(data->controlmap[data->mat_y][data->mat_x] == 'E')
                mlx_put_image_to_window(data->mlx, data->mlx_window, data->img[7], data->mat_x * 64, data->mat_y * 64);
            data->mat_x++;
        }
        data->mat_y++;
    }
}

int	ft_keyboard(int keyhook, t_data *game)
{
    if (keyhook == 53)
    {
		mlx_destroy_window(game->mlx, game->mlx_window);
	    exit(0);
    }
	if (game->collectnum == 0
		&& ((keyhook == 2 && \
		game->controlmap[game->position_y][game->position_x + 1] == 'E')
		|| (keyhook == 1 && \
		game->controlmap[game->position_y + 1][game->position_y] == 'E')
		|| (keyhook == 0 && \
		game->controlmap[game->position_y][game->position_y - 1] == 'E')
		|| (keyhook == 13 && \
		game->controlmap[game->position_y - 1][game->position_x] == 'E')))
	{
		printf("Walk Count: %d\n", game->step + 1);
		printf("Game Over!! YOU WON!!\n");
		mlx_destroy_window(game->mlx, game->mlx_window);
	    exit(0);
	}
	ft_key_hook(keyhook, game);
	hookles(game);
	return (0);
}

void	ft_key_hook(int keyhook, t_data *game)
{
	if (keyhook == 13 && \
		game->controlmap[game->position_y - 1][game->position_y] != '1'
		&& game->controlmap[game->position_y - 1][game->position_x] != 'E')
	{
        game->position_y-=64;
        game->step+=1;
        mlx_put_image_to_window(game->mlx, game->mlx_window,
            game->img[3], game->position_x, game->position_y);
    }
	if (keyhook == 0 && game->controlmap[game->position_y][game->position_x - 1] != '1'
		&& game->controlmap[game->position_y][game->position_x - 1] != 'E')
    {
		game->position_x-=64;
        game->step+=1;
        mlx_put_image_to_window(game->mlx, game->mlx_window,
            game->img[2], game->position_x, game->position_y);
    }
	if (keyhook == 1 && game->controlmap[game->position_y + 1][game->position_x] != '1'
		&& game->controlmap[game->position_y + 1][game->position_x] != 'E')
    {
        game->position_y+=64;
        game->step+=1;
		mlx_put_image_to_window(game->mlx, game->mlx_window,
            game->img[0], game->position_x, game->position_y);
    }
	if (keyhook == 2 && game->controlmap[game->position_y][game->position_x + 1] != '1'
		&& game->controlmap[game->position_y][game->position_x + 1] != 'E')
	{
        game->position_x+=64;
        game->step+=1;
        mlx_put_image_to_window(game->mlx, game->mlx_window,
            game->img[1], game->position_x, game->position_y);
    }
}

void ft_startcharacter(t_data *data)
{
    data->position_x = find_player_x(data->map) * 64;
    data->position_y = find_player_y(data->map) * 64;

    mlx_put_image_to_window(data->mlx, data->mlx_window,
            data->img[0], data->position_x, data->position_y);

}