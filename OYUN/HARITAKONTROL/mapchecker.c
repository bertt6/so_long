#include "so_long.h"

void    ft_map_playable_control(t_data *game)
{
    ft_map_control_v1(game);
    ft_map_control_v2(game);
    ft_map_control_v3(game);
    ft_map_control_v4(game);
}

void    ft_map_control_v1(t_data *game)
{
    if (game->map[game->player_y + 1][game->player_x] != '.' && \
        game->map[game->player_y + 1][game->player_x] != '1')
    {
        game->map[game->player_y][game->player_x] = '.';
        game->player_y++;
        if (game->map[game->player_y][game->player_x] == 'C')
            game->collect--;
        if (game->map[game->player_y][game->player_x] == 'E')
        {
            if (game->collect != 0)
            {
                game->player_y--;
                game->exit--;
                return ;
            }
            game->exit--;
        }
        ft_map_playable_control(game);
        game->player_y--;
    }
}

void    ft_map_control_v2(t_data *game)
{
    if (game->map[game->player_y][game->player_x + 1] != '.' && \
        game->map[game->player_y][game->player_x + 1] != '1')
    {
        game->map[game->player_y][game->player_x] = '.';
        game->player_x++;
        if (game->map[game->player_y][game->player_x] == 'C')
            game->collect--;
        if (game->map[game->player_y][game->player_x] == 'E')
        {
            if (game->collect != 0)
            {
                game->player_x--;
                game->exit--;
                return ;
            }
            game->exit--;
        }
        ft_map_playable_control(game);
        game->player_x--;
    }
}

void    ft_map_control_v3(t_data *game)
{
    if (game->map[game->player_y - 1][game->player_x] != '.' && \
        game->map[game->player_y - 1][game->player_x] != '1')
    {
        game->map[game->player_y][game->player_x] = '.';
        game->player_y--;
        if (game->map[game->player_y][game->player_x] == 'C')
            game->collect--;
        if (game->map[game->player_y][game->player_x] == 'E')
        {
            if (game->collect != 0)
            {
                game->player_y++;
                game->exit--;
                return ;
            }
            game->exit--;
        }
        ft_map_playable_control(game);
        game->player_y++;
    }
}

void    ft_map_control_v4(t_data *game)
{
    if (game->map[game->player_y][game->player_x - 1] != '.' && \
        game->map[game->player_y][game->player_x - 1] != '1')
    {
        game->map[game->player_y][game->player_x] = '.';
        game->player_x--;
        if (game->map[game->player_y][game->player_x] == 'C')
            game->collect--;
        if (game->map[game->player_y][game->player_x] == 'E')
        {
            if (game->collect != 0)
            {
                game->player_x++;
                game->exit--;
                return ;
            }
            game->exit--;
        }
        ft_map_playable_control(game);
        game->player_x++;
    }
}

