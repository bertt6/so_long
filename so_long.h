/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamli <bsamli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:03:29 by bsamli            #+#    #+#             */
/*   Updated: 2023/01/14 14:58:02 by bsamli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define     PL_FT "xpms/player_front.xpm"
# define     PL_LT "xpms/player_left.xpm"
# define     PL_RT "xpms/player_right.xpm"
# define     PL_BC "xpms/player_back.xpm"
# define     GR "xpms/game_ground.xpm"
# define     WLL "xpms/wall.xpm"
# define     COIN "xpms/coin.xpm"
# define     DOR "xpms/door.xpm"
# define     WIN_WEIGHT 1800
# define     WIN_HEIGHT 1200

# ifndef ANIMATION_FRAMES
#  define ANIMATION_FRAMES 10
# endif

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include "mlx/mlx.h"
# include <string.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_data
{
	int		mat_y;
	int		mat_x;
	void	*mlx;
	void	*mlx_window;
	void	**img;
	int		imgx;
	int		imgy;
	int		position_x;
	int		position_y;
	int		key;
	char	**map;
	char	**controlmap;
	int		height;
	int		width;
	int		step;
	int		collectnum;
	int		coin;
	int		exit;
}				t_data;

int		find_player_x(char *map[]);
int		find_player_y(char *map[]);

void	ft_move_up(t_data *game);
void	ft_move_down(t_data *game);
void	ft_move_left(t_data *game);
void	ft_move_right(t_data *game);

int		ft_keyboard(int keyhook, t_data *game);

void	find_player(t_data *data);
void	recursive_control(t_data *data, int x, int y);
void	start_control(t_data *data, int x, int y);
void	second_control(t_data *data, int x, int y);
void	third_control(t_data *data, int x, int y);
void	fourth_control(t_data *data, int x, int y);

void	exit_check(char *map[]);
void	coin_check(char *map[]);

void	top_left_wall_control(t_data *game);
void	right_bottom_wall_control(t_data *game);
void	playable_control(t_data *game);
void	map_checking(t_data *data);

void	line_control(t_data *data);
void	collectable_control(t_data *data);
void	door_control(t_data *data);
int		bercheck(char *s);
void	hookles(t_data *data);
void	ft_putimages1(t_data *data, int mat_x, int mat_y);
void	ft_key_hook(int keyhook, t_data *game);
void	can_go_exit(t_data *data);
void	ft_putimages(t_data *data);
void	ft_window(t_data *data);
void	*ft_calloc(size_t count, size_t size);
int		map_width(char *map[]);
int		map_height(char *map[]);
int		ft_close(int key, t_data *data);
int		mouse(int button, int x, int y, t_data *data);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
char	*ft_itoa(int n);
char	*ft_strdup(const char *s1);

void	mapreader(t_data *data, char *map);

void	ft_putstr(char *s, int *result);
void	ft_putnbr(int n, int *result);
void	ft_putchar(char c, int *result);
void	ft_dhex(unsigned int i, int *result);
void	ft_uhex(unsigned int i, int *result);
void	ft_unsigned(unsigned int i, int *result);
void	ft_pointer(unsigned long long i, int *result);
void	ft_check(va_list *list, char a, int *result);
int		ft_printf(const char *s, ...);

void	ft_argcheck(char *map[]);
char	*ft_substr(char	const *s, unsigned int start, size_t len);
int		ftcount(char const *s, char c);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_read(int fd);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

#endif
