#ifndef SO_LONG_H
# define SO_LONG_H

#define     PL_FT "./player_front.xpm"
#define     PL_LT "./player_left.xpm"
#define     PL_RT "./player_right.xpm"
#define     PL_BC "./player_back.xpm"
#define     GR "./game_ground.xpm"
#define     WIN_WEIGHT 1800
#define     WIN_HEIGHT 1200

# ifndef ANIMATION_FRAMES
#  define ANIMATION_FRAMES 10
# endif

# include <stdio.h>
# include <stdlib.h>
# include "mlx/mlx.h"
# include <string.h>

typedef struct s_data
{
    char        **visited;
    char        **matrix;
    int         mat_y;
    int         mat_x;
    void        *mlx;
    void        *mlx_window;
    void        **img;
    int         imgx;
    int         imgy;
    int         position_x;
    int         position_y;
    int         key;
}               t_data;


int     close(int key, t_data *data);
int     key_event(int keycode, t_data *data);
int     mouse(int   button ,int  x, int y, t_data *data);
int	    ftcount(char const *s, char c);
char	**ft_split(char const *s, char c);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);

#endif