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
    data->key = keycode;
    
    if (keycode == 13)//w harfi
    {
        data->position_y-=64;
        data->step+=1;
    }
    if (keycode == 2)//d harfi
    {
        data->position_x+=64;
                data->step+=1;
    }
    if (keycode == 1)//s harfi
    {
        data->position_y+=64;
                data->step+=1;
    }
    if (keycode == 0)//a harfi
    {
        data->position_x-=64;
                data->step+=1;
    }
    if (keycode == 53)
        exit(1);

    if (data->collectnum == 0
		&& ((keycode == 2 && \
		data->controlmap[data->position_y][data->position_x + 1] == 'E')
		|| (keycode == 1 && \
		data->controlmap[data->position_y + 1][data->position_y] == 'E')
		|| (keycode == 0 && \
		data->controlmap[data->position_y][data->position_y - 1] == 'E')
		|| (keycode == 13 && \
		data->controlmap[data->position_y - 1][data->position_x] == 'E')))
	{
		printf("Walk Count: %d\n", data->step + 1);
		printf("Game Over!! YOU WON!!\n");
		mlx_destroy_window(data->mlx, data->mlx_window);
	    exit(0);
	}
    printf("CONTROL1\n");
	ft_key_hook(keycode, data);
	hookles(data);
    printf("CONTROL3\n");
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

	t_data	*program = param;
	static int	frame;
	frame++;
	if (frame == ANIMATION_FRAMES)
		program->position_y += 1;
	else if (frame >= (ANIMATION_FRAMES) * 2)
	{
		program->position_y -= 1;
		frame = 0;
	}
    
   
	return (0);
}

int	bercheck(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	if (s[i - 1] != 'r' || s[i - 2] != 'e' || s[i - 3] != 'b' || \
		s[i - 4] != '.' || i < 5)
	{
		printf("%sWrong file name!\n", "\x1B[31m");
		return (0);
	}
	return (1);
}

int    main(int ac, char **av)
{
    if(ac == 2)
    {
        if(!bercheck(av[1]))
            return 0;
        t_data    *data;  
        data = calloc(sizeof(t_data), 1);
        data->key = 1;
        data->img = (void **)ft_calloc(sizeof(void *), 7);
        data->mlx = mlx_init();

        
        int fd = open(av[1], O_RDWR);
        char *s = ft_read(fd);
        data->map = ft_split(s, '\n');

        data->height = map_height(data->map);
        data->width = map_width(data->map);
        
        data->controlmap = data->map;
        data->mat_y = data->height;
        data->mat_x = data->width;

        ft_argcheck(data->map);
        ft_window(data);
    }
    else
    {
        printf("Lütfen geçerli bir harita giriniz. -./so_long map.ber-");
        exit(1);
    }
}
