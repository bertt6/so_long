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
    (void)data;
    return(0);
}

void map_checking(t_data *data)
{
    top_left_wall_control(data);
    right_bottom_wall_control(data);
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
		ft_printf("%sYanlış dosya adı!\n", "\x1B[31m");
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
        data->img = (void **)ft_calloc(sizeof(void *), 4);

        
        int fd = open(av[1], O_RDWR);
        char *s = ft_read(fd);
        data->map = ft_split(s, '\n');
        data->controlmap = ft_split(s, '\n');

    
        data->height = map_height(data->map);
        data->width = map_width(data->map);
        
        data->mat_y = data->height;
        data->mat_x = data->width;

        line_control(data);
        map_checking(data);
        find_player(data);
        collectable_control(data);
        door_control(data);
        coin_check(data->map);
        exit_check(data->map);
        ft_argcheck(data->map);
        ft_window(data);
    }
    else
    {
        ft_printf("Lütfen geçerli bir harita giriniz. -./so_long map.ber-");
        exit(1);
    }
}
