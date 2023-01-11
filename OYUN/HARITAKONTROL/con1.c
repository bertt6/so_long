#include "../so_long.h"

void playable_control(t_data *data)
{
    
}

void first_control(t_data *data)
{
    if(data->controlmap[data->position_y + 1] [data->position_x] != '.' && \
       data->controlmap[data->position_y + 1][data->position_x] != '1')
    {
        data->controlmap[data->position_y] [data->position_x] = '.';
        
        playable_control(data);
    }
}