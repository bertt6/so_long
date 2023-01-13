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
                recursive_control(data, j, i);
                return ;
            }
            j++;
        }
        i++;
    }
}

void recursive_control(t_data *data, int x, int y)
{
    start_control(data, x, y);
    second_control(data, x, y);
    third_control(data, x, y);
    fourth_control(data, x, y);
}

void start_control(t_data *data, int x, int y)
{
    if (data->controlmap[y + 1][x] != '.' && \
        data->controlmap[y + 1][x] != '1')
    {
        y++;
        if(data->controlmap[y][x] == 'E')
			data->exit++;
        if(data->controlmap[y][x] == 'C')
			data->collectnum++;
        data->controlmap[y][x] = '.';
        recursive_control(data, x, y);
        y--;
    }
}

void second_control(t_data *data, int x, int y)
{
    if (data->controlmap[y][x + 1] != '.' && \
        data->controlmap[y][x + 1] != '1')
    {
        x++;
        if(data->controlmap[y][x] == 'E')
			data->exit++;
        if(data->controlmap[y][x] == 'C')
			data->collectnum++;
        data->controlmap[y][x] = '.';
        recursive_control(data, x, y);
        x--;
    }
}

void third_control(t_data *data, int x, int y)
{
    if (data->controlmap[y - 1][x] != '.' && \
        data->controlmap[y - 1][x] != '1')
    {
        y--;
        if(data->controlmap[y][x] == 'E')
			data->exit++;
        if(data->controlmap[y][x] == 'C')
			data->collectnum++;
        data->controlmap[y][x] = '.';
        recursive_control(data, x, y);
        y++;
    }
}

void fourth_control(t_data *data, int x, int y)
{
    if (data->controlmap[y][x - 1] != '.' && \
        data->controlmap[y][x - 1] != '1')
    {
        x--;
        if(data->controlmap[y][x] == 'E')
			data->exit++;
        if(data->controlmap[y][x] == 'C')
			data->collectnum++;
        data->controlmap[y][x] = '.';
        recursive_control(data, x, y);
        x++;
    }
}