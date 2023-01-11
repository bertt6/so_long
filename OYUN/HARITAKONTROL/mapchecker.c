#include "../so_long.h"

void    ft_map_playable_control(t_data *game, int pos_x, int pos_y)
{
    control1(game, pos_x, pos_y);
    control2(game, pos_x, pos_y);
    control3(game, pos_x, pos_y);
    control4(game, pos_x, pos_y);
}

void    control1(t_data *game, int pos_x, int pos_y)
{
    if (game->controlmap[pos_y + 1][pos_x] != '.' && \
        game->controlmap[pos_y + 1][pos_x] != '1')
    {
        game->controlmap[pos_y][pos_x] = '.';
        pos_y++;
        if (game->controlmap[pos_y][pos_x] == 'C')
            game->collectnum--;
        if (game->controlmap[pos_y][pos_x] == 'E')
        {
            if (game->collectnum != 0)
            {
                pos_y--;
                game->exit--;
                return ;
            }
            game->exit--;
        }
        pos_y--;
        ft_map_playable_control(game, pos_x, pos_y);
    }
}

void    control2(t_data *game, int pos_x, int pos_y)
{
    if (game->controlmap[pos_y][pos_x + 1] != '.' && \
        game->controlmap[pos_y][pos_x + 1] != '1')
    {
        game->controlmap[pos_y][pos_x] = '.';
        pos_x++;
        if (game->controlmap[pos_y][pos_x] == 'C')
            game->collectnum--;
        if (game->controlmap[pos_y][pos_x] == 'E')
        {
            if (game->collectnum != 0)
            {
                pos_x--;
                game->exit--;
                return ;
            }
            game->exit--;
        }
        pos_x--;
        ft_map_playable_control(game, pos_x, pos_y);
    }
}

void    control3(t_data *game, int pos_x, int pos_y)
{
    if (game->controlmap[pos_y - 1][pos_x] != '.' && \
        game->controlmap[pos_y - 1][pos_x] != '1')
    {
        game->controlmap[pos_y][pos_x] = '.';
        pos_y--;
        if (game->controlmap[pos_y][pos_x] == 'C')
            game->collectnum--;
        if (game->controlmap[pos_y][pos_x] == 'E')
        {
            if (game->collectnum != 0)
            {
                pos_y++;
                game->exit--;
                return ;
            }
            game->exit--;
        }
        pos_y++;
        ft_map_playable_control(game, pos_x, pos_y);
    }
}

void    control4(t_data *game, int pos_x, int pos_y)
{
   
    if (game->controlmap[pos_y][pos_x - 1] != '.' && \
        game->controlmap[pos_y][pos_x - 1] != '1')
    {
        game->controlmap[pos_y][pos_x] = '.';
        pos_x--;
        if (game->controlmap[pos_y][pos_x] == 'C')
            game->collectnum--;
        if (game->controlmap[pos_y][pos_x] == 'E')
        {
            if (game->collectnum != 0)
            {
                pos_x++;
                game->exit--;
                return ;
            }
            game->exit--;
        }
        ft_map_playable_control(game, pos_x, pos_y);
        pos_x++;
    }
}
