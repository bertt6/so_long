#include "../so_long.h"

void find_player(t_data *data)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(data->controlmap[i])
    {
        j = 0;
        while(data->controlmap[i][j])
        {
            if(data->controlmap[i][j] == 'P')
            {
                recursive_control(data, i, j);
                return ;
            }
            j++;
        }
        i++;
    }
}

void recursive_control(t_data *data, int x, int y)
{
    int i = 0;
    printf("\nX = %d, Y = %d\n", x, y);
    while(data->controlmap[i])
    {
        printf("\nMAP = %s\n", data->controlmap[i]);
        i++;
    }
    start_control(data, x, y);
    second_control(data, x, y);
    third_control(data, x, y);
    fourth_control(data, x, y);
}

void start_control(t_data *game, int x, int y)
{
    

    if (game->controlmap[y + 1][x] != '.' && \
        game->controlmap[y + 1][x] != '1')
    {
        game->controlmap[y][x] = '.';
        y++;
        if (game->controlmap[y][x] == 'C')
            game->collectnum--;
        if (game->controlmap[y][x] == 'E')
        {
            if (game->collectnum != 0)
            {
                y--;
                game->exit--;
                return ;
            }
            game->exit--;
        }
        recursive_control(game, x, y);
        y--;
    }
}

void second_control(t_data *data, int x, int y)
{
    if (data->controlmap[y][x + 1] != '.' && \
        data->controlmap[y][x + 1] != '1')
    {
        data->controlmap[y][x] = '.';
        x++;
        if (data->controlmap[y][x] == 'C')
            data->collectnum--;
        if (data->controlmap[y][x] == 'E')
        {
            if (data->collectnum != 0)
            {
                x--;
                data->exit--;
                return ;
            }
            data->exit--;
        }
        recursive_control(data, x, y);
        x--;
    }
}

void third_control(t_data *data, int x, int y)
{
    if (data->controlmap[y - 1][x] != '.' && \
        data->controlmap[y - 1][x] != '1')
    {
        data->controlmap[y][x] = '.';
        y--;
        if (data->controlmap[y][x] == 'C')
            data->collectnum--;
        if (data->controlmap[y][x] == 'E')
        {
            if (data->collectnum != 0)
            {
                y++;
                data->exit--;
                return ;
            }
            data->exit--;
        }
        recursive_control(data, x, y);
        y++;
    }
}

void fourth_control(t_data *data, int x, int y)
{
    if (data->controlmap[y][x - 1] != '.' && \
        data->controlmap[y][x - 1] != '1')
    {
        data->controlmap[y][x] = '.';
        x--;
        if (data->controlmap[y][x] == 'C')
            data->collectnum--;
        if (data->controlmap[y][x] == 'E')
        {
            if (data->collectnum != 0)
            {
                x++;
                data->exit--;
                return ;
            }
            data->exit--;
        }
        recursive_control(data, x, y);
        x++;
    }
}