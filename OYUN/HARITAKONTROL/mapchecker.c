#include "../so_long.h"
/*
void    ft_map_playable_control(t_data *game, int pos_x, int pos_y)
{
    control1(game, pos_x, pos_y);
    control2(game, pos_x, pos_y);
    control3(game, pos_x, pos_y);
    control4(game, pos_x, pos_y);
}

void    control1(t_data *game, int pos_x, int pos_y)
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
        game->position_y--;
        ft_map_playable_control(game, pos_x, pos_y);
    }
}

void    control2(t_data *game, int pos_x, int pos_y)
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
        game->position_x--;
        ft_map_playable_control(game);
    }
}

void    control3(t_data *game, int pos_x, int pos_y)
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
        game->position_y++;
        ft_map_playable_control(game);
    }
}

void    control4(t_data *game, int pos_x, int pos_y)
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
*/