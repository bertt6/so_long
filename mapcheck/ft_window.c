#include "../so_long.h"

void ft_window(t_data *data)
{
    data->mlx = mlx_init();
    data->mlx_window = mlx_new_window(data->mlx, data->width * 64, 
    data->height * 64, "SO_LONG");
    data->img[0] = mlx_xpm_file_to_image(data->mlx, PL_FT,
        &data->imgx, &data->imgy);
    data->img[1] = mlx_xpm_file_to_image(data->mlx, GR,
        &data->imgx, &data->imgy);
    data->img[2] = mlx_xpm_file_to_image(data->mlx, WLL, 
        &data->imgx, &data->imgy);
    data->img[3] = mlx_xpm_file_to_image(data->mlx, COIN, 
        &data->imgx, &data->imgy);
    data->img[4] = mlx_xpm_file_to_image(data->mlx, DOR, 
        &data->imgx, &data->imgy);
    hookles(data);
}

void hookles(t_data *data)
{
    char *step;

    data->coin = 0;
    data->mat_x = 0;
    data->mat_y = 0;
    step = ft_itoa(data->step);
    ft_putimages(data);
    mlx_hook(data->mlx_window, 2, 0, ft_keyboard, data);
    mlx_hook(data->mlx_window, 4, 0, mouse, data);
    mlx_string_put(data->mlx, data->mlx_window, 10, 20, 0x00FF00, "Step :");
    mlx_string_put(data->mlx, data->mlx_window, 80, 20, 0x00FF00, step);
	free(step);
    mlx_loop(data->mlx);
}

void	ft_putimages(t_data *data)
{
	mlx_clear_window(data->mlx, data->mlx_window);
	while (data->map[data->mat_y])
	{
		data->mat_x = 0;
		while (data->map[data->mat_y][data->mat_x])
		{
			mlx_put_image_to_window(data->mlx, data->mlx_window, data->img[1], data->mat_x * 64, data->mat_y * 64);
			if (data->map[data->mat_y][data->mat_x] == '1')
                mlx_put_image_to_window(data->mlx, data->mlx_window, data->img[2], data->mat_x * 64, data->mat_y * 64);
			if (data->map[data->mat_y][data->mat_x] == 'P')
			{
                mlx_put_image_to_window(data->mlx, data->mlx_window, data->img[0], data->mat_x * 64, data->mat_y * 64);
				data->position_x = data->mat_x;
				data->position_y = data->mat_y;
			}				
			if (data->map[data->mat_y][data->mat_x] == 'C')
			{
				mlx_put_image_to_window(data->mlx, data->mlx_window, data->img[3], data->mat_x * 64, data->mat_y * 64);
				data->coin++;
			}
			if (data->map[data->mat_y][data->mat_x] == 'E')
			{
                mlx_put_image_to_window(data->mlx, data->mlx_window, data->img[4], data->mat_x * 64, data->mat_y * 64);
			}
			if (data->map[data->mat_y][data->mat_x] == '0')
				mlx_put_image_to_window(data->mlx, data->mlx_window, data->img[1], data->mat_x * 64, data->mat_y * 64);
			data->mat_x ++;
		}
		data->mat_y++;
	}
	can_go_exit(data);
}

void can_go_exit(t_data *data)
{
	char *coin;

	coin = ft_itoa(data->coin);
	mlx_string_put(data->mlx, data->mlx_window, 10, 50, 0x00FF00, "COIN : ");
	mlx_string_put(data->mlx, data->mlx_window, 80, 50, 0x00FF00, coin);
	free(coin);
	if(data->coin == 0)
	{
		mlx_string_put(data->mlx, data->mlx_window, 10, 82, 0xFFFFFF, "KAPIYA GIDEBILIRSIN!");
	}
}

void	ft_key_hook(int keyhook, t_data *data)
{
	if (keyhook == 13 && data->map[data->position_y - 1][data->position_x] != '1'
		&& data->map[data->position_y - 1][data->position_x] != 'E')
        ft_move_up(data);	
	if (keyhook == 0 && data->map[data->position_y][data->position_x - 1] != '1'
		&& data->map[data->position_y][data->position_x - 1] != 'E')
        ft_move_left(data);
	if (keyhook == 1 && data->map[data->position_y + 1][data->position_x] != '1'
		&& data->map[data->position_y + 1][data->position_x] != 'E')
        ft_move_down(data);
	if (keyhook == 2 && data->map[data->position_y][data->position_x + 1] != '1'
		&& data->map[data->position_y][data->position_x + 1] != 'E')
        ft_move_right(data);
	ft_printf("Adim sayisi : %d\n", data->step);
}

int	ft_keyboard(int keyhook, t_data *data)
{
	ft_putimages(data);
	if (keyhook == 53)
        exit(1);
	if (data->coin == 0
		&& ((keyhook == 2 && \
		data->map[data->position_y][data->position_x + 1] == 'E')
		|| (keyhook == 1 && \
		data->map[data->position_y + 1][data->position_x] == 'E')
		|| (keyhook == 0 && \
		data->map[data->position_y][data->position_x - 1] == 'E')
		|| (keyhook == 13 && \
		data->map[data->position_y - 1][data->position_x] == 'E')))
	{
		ft_printf("Adim sayisi: %d\n", data->step + 1);
		ft_printf("Oyun bitti! Kazandiniz!\n");
		free(data->img);
		exit(1);
	}
	ft_key_hook(keyhook, data);
	hookles(data);

	return (0);
}