#include "so_long.h"

int ft_close(int key, t_data *data)
{
    (void)data;
    if(key == 53)
        exit(0);
    return 0;
}

int    key_event(int keycode, t_data *data)
{
    mlx_clear_window(data->mlx, data->mlx_window);
    int a;
    int b;

    a = 0;
    data->key = keycode;
    while (a < 30)
    {
        b = 0;
        while (b < 30)
        {
            mlx_put_image_to_window(data->mlx, data->mlx_window, data->img[4],
            a * 64, b * 64);
            b++;
        }
        a++;
    }
    /*  13 -> W
        1  -> S
        0  -> A
        2  -> D
        FRONT -> 0
        LEFT  -> 1
        RIGHT -> 2
        BACK  -> 3*/
    if (keycode == 13)//w harfi
        data->position_y-=64;

    if (keycode == 2)//d harfi
        data->position_x+=64;

    if (keycode == 1)//s harfi
        data->position_y+=64;
    
    if (keycode == 0)//a harfi
        data->position_x-=64;
    
    if (keycode == 53)
        exit(1);

    return (0);
}



int    mouse(int   button ,int  x, int y, t_data *data)
{
    int z = x + y + button; 
    (void)z;
    printf("posx %d posy %d\n", data->position_x, data->position_y);    
    return(0);
}

int	ft_update (t_data *param)
{
    /*  13 -> W
        1  -> S
        0  -> A
        2  -> D
        FRONT -> 0
        LEFT  -> 1
        RIGHT -> 2
        BACK  -> 3*/
    int x;
	t_data	*program = param;
	static int	frame;
	frame++;
	if (frame == ANIMATION_FRAMES)
		program->position_y += 1;
	else if (frame >= ANIMATION_FRAMES * 2)
	{
		program->position_y -= 1;
		frame = 0;
	}
    x = param->key;
    if(param->key == 1) // S
    {
        mlx_put_image_to_window(program->mlx, program->mlx_window,
            program->img[0], program->position_x, program->position_y);
    }
    else if (param->key == 13) //W
    {
         mlx_put_image_to_window(program->mlx, program->mlx_window,
            program->img[3], program->position_x, program->position_y);
    }
    else if (param->key == 0) // A
    {
        mlx_put_image_to_window(program->mlx, program->mlx_window,
            program->img[2], program->position_x, program->position_y);
    }
    else if(param->key == 2) //D
    {
        mlx_put_image_to_window(program->mlx, program->mlx_window,
            program->img[1], program->position_x, program->position_y);
    }
	return (0);
}

int    main(void)
{
    
    t_data    *data;
    
    data = calloc(sizeof(t_data), 1);
    data->key = 1;
    data->img = (void **)calloc(sizeof(void *), 4);
    
    data->mlx = mlx_init();
    data->map =

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
    
    int fd = open("map.ber", O_RDWR);
    data->map = ft_read(fd);

    data->matrix = ft_split(data->map, '\n');
    data->visited = ft_split(data->map, '\n');
    data->mlx_window = mlx_new_window(data->mlx, WIN_WEIGHT, WIN_HEIGHT, "Pencere :D");

    data->position_x = 300;
    data->position_y = 200;

    data->mat_y = WIN_HEIGHT;
    data->mat_x = WIN_WEIGHT;


    int a;
    int b;

    a = 0;
    while (a < 30)
    {
        b = 0;
        while (b < 30)
        {
            mlx_put_image_to_window(data->mlx, data->mlx_window, data->img[4],
            a * 64, b * 64);
            b++;
        }
        a++;
    }
    ft_path_find(data);

    mlx_hook(data->mlx_window, 2, 0, key_event, data);
    mlx_hook(data->mlx_window, 4, 0, mouse, data);
	mlx_loop_hook(data->mlx, *ft_update, data);
    mlx_loop(data->mlx);
}