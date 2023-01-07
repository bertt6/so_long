#include "so_long.h"

void	ft_move_up(t_data *game)
{
	if (game->controlmap[game->position_y - 1][game->position_x] == 'C')
		game->collectnum--;
	game->controlmap[game->position_y][game->position_x] = '0';
	game->controlmap[game->position_y - 1][game->position_x] = 'P';
	game->position_y--;
	game->step++;
}

void	ft_move_down(t_data *game)
{
	if (game->controlmap[game->position_y + 1][game->position_x] == 'C')
		game->collectnum--;
	game->controlmap[game->position_y][game->position_x] = '0';
	game->controlmap[game->position_y + 1][game->position_x] = 'P';
	game->position_y++;
	game->step++;
}

void	ft_move_left(t_data *game)
{
	if (game->controlmap[game->position_y][game->position_x - 1] == 'C')
		game->collectnum--;
	game->controlmap[game->position_y][game->position_x] = '0';
	game->controlmap[game->position_y][game->position_x - 1] = 'P';
	game->step++;
	game->position_x--;
}

void	ft_move_right(t_data *game)
{
	if (game->controlmap[game->position_y][game->position_x + 1] == 'C')
		game->collectnum--;
	game->controlmap[game->position_y][game->position_x] = '0';
	game->controlmap[game->position_y][game->position_x + 1] = 'P';
	game->step++;
	game->position_x++;
}

