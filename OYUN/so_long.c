#include "so_long.h"

int ft_close(int key, t_data *data)
{
    (void)data;
    if(key == 53)
        exit(0);
    return 0;
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
		printf("%sYanlış dosya adı!\n", "\x1B[31m");
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

        
        int fd = open(av[1], O_RDWR);
        char *s = ft_read(fd);
        data->map = ft_split(s, '\n');
        data->controlmap = ft_split(s, '\n');

        data->height = map_height(data->map);
        data->width = map_width(data->map);
        
        data->mat_y = data->height;
        data->mat_x = data->width;

        coin_check(data->map);
        exit_check(data->map);
        ft_player_find(data);
        ft_argcheck(data->map);
        ft_window(data);
    }
    else
    {
        printf("Lütfen geçerli bir harita giriniz. -./so_long map.ber-");
        exit(1);
    }
}
