#include "../so_long.h"

void    ft_map_playable_control(t_data *game)
{
    // int i;

    // i = 0;
    // while(game->controlmap[i])
    // {
    //     printf("\n%s\n", game->controlmap[i]);
    //     i++;
    // }
    control1(game);
    control2(game);
    control3(game);
    control4(game);
}

void    control1(t_data *game)
{
    if (game->controlmap[game->position_y + 1][game->position_x] != '.' && \
        game->controlmap[game->position_y + 1][game->position_x] != '1')
    {
        game->controlmap[game->position_y][game->position_x] = '.';
        game->position_y++;
        if (game->controlmap[game->position_y][game->position_x] == 'C')
            game->collectnum--;
        if (game->controlmap[game->position_y][game->position_x] == 'E')
        {
            if (game->collectnum != 0)
            {
                game->position_y--;
                game->exit--;
                return ;
            }
            game->exit--;
        }
        ft_map_playable_control(game);
        game->position_y--;
    }
}

void    control2(t_data *game)
{
    if (game->controlmap[game->position_y][game->position_x + 1] != '.' && \
        game->controlmap[game->position_y][game->position_x + 1] != '1')
    {
        game->controlmap[game->position_y][game->position_x] = '.';
        game->position_x++;
        if (game->controlmap[game->position_y][game->position_x] == 'C')
            game->collectnum--;
        if (game->controlmap[game->position_y][game->position_x] == 'E')
        {
            if (game->collectnum != 0)
            {
                game->position_x--;
                game->exit--;
                return ;
            }
            game->exit--;
        }
        ft_map_playable_control(game);
        game->position_x--;
    }
}

void    control3(t_data *game)
{
    if (game->controlmap[game->position_y - 1][game->position_x] != '.' && \
        game->controlmap[game->position_y - 1][game->position_x] != '1')
    {
        game->controlmap[game->position_y][game->position_x] = '.';
        game->position_y--;
        if (game->controlmap[game->position_y][game->position_x] == 'C')
            game->collectnum--;
        if (game->controlmap[game->position_y][game->position_x] == 'E')
        {
            if (game->collectnum != 0)
            {
                game->position_y++;
                game->exit--;
                return ;
            }
            game->exit--;
        }
        ft_map_playable_control(game);
        game->position_y++;
    }
}

void    control4(t_data *game)
{
    if (game->controlmap[game->position_y][game->position_x - 1] != '.' && \
        game->controlmap[game->position_y][game->position_x - 1] != '1')
    {
        game->controlmap[game->position_y][game->position_x] = '.';
        game->position_x--;
        if (game->controlmap[game->position_y][game->position_x] == 'C')
            game->collectnum--;
        if (game->controlmap[game->position_y][game->position_x] == 'E')
        {
            if (game->collectnum != 0)
            {
                game->position_x++;
                game->exit--;
                return ;
            }
            game->exit--;
        }
        ft_map_playable_control(game);
        game->position_x++;
    }
}

