#include "../so_long.h"



void ft_put_images(t_data *data)
{
    int i;
    int j;
    int a;
    int b;
    char **map;
    map = data->map;

    i = 0;
    a = 0;
    b = 0;
    j = 0;
    mlx_clear_window(data->mlx, data->mlx_window);
    while (a < data->height)
    {
        b = 0;
        while (b < data->width)
        {
            mlx_put_image_to_window(data->mlx, data->mlx_window, data->img[5],
            a * 64, b * 64);
            b++;
        }
        a++;
    }
    while(map[i])
    {
        j = 0;
        while(map[i][j])
        {
            if(map[i][j] == '0')
            {
                printf("%d\n", j);
                mlx_put_image_to_window(data->mlx, data->mlx_window, data->img[5], i * 64, j * 64);
            }
            j++;
        }
        i++;
    }
}