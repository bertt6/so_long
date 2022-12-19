#include "./mlx/mlx.h"
#include <stdlib.h>
#define PL_FT "./player_front.xpm"
#define PL_LT "./player_left.xpm"
#define PL_RT "./player_right.xpm"
#define PL_BC "./player_back.xpm"
#define GR "./game_ground.xpm"
#include <stdio.h>
#define WIN_WEIGHT 1800
#define WIN_HEIGHT 1200


typedef struct s_data
{
    void    *mlx;
    void    *mlx_window;
    void    **img;
    int        imgx;
    int        imgy;
    int        position_x;
    int        position_y;
}    t_data;

int close(int key, t_data *data)
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
    if (keycode == 2)//d harfi
    {
        data->position_x+=64;
        mlx_put_image_to_window(data->mlx, data->mlx_window, data->img[1],
                data->position_x, data->position_y);
    }
    if (keycode == 1)//s harfi
    {
        data->position_y+=64;
        mlx_put_image_to_window(data->mlx, data->mlx_window, data->img[0],
                data->position_x, data->position_y);
    }
    if (keycode == 13)//w harfi
    {
        data->position_y-=64;
        mlx_put_image_to_window(data->mlx, data->mlx_window, data->img[3],
                data->position_x, data->position_y);
    }
    if (keycode == 0)//a harfi
    {
        data->position_x-=64;
        mlx_put_image_to_window(data->mlx, data->mlx_window, data->img[2],
                data->position_x, data->position_y);
    }
    if (keycode == 53)
    {
        exit(1);
    }
    return (0);
}
int    mouse(int   button ,int  x, int y, t_data *data)
{
    int z = x + y + button; 
    (void)z;
    printf("posx %d posy %d\n", data->position_x, data->position_y);    
    return(0);
}

int    main(void)
{
    t_data    *data;
    data = calloc(sizeof(t_data), 1);
    data->img = (void **)malloc(sizeof(void *) * 4);

    data->mlx = mlx_init();
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

    data->mlx_window = mlx_new_window(data->mlx, WIN_WEIGHT, WIN_HEIGHT, "Pencere :D");

    data->position_x = 300;
    data->position_y = 200;


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
    mlx_put_image_to_window(data->mlx, data->mlx_window, data->img[0],
            data->position_x, data->position_y);
    mlx_hook(data->mlx_window, 2, 0, key_event, data);
    mlx_hook(data->mlx_window, 4, 0, mouse, data);
    mlx_loop(data->mlx);
}