#ifndef SO_LONG_H
# define SO_LONG_H

#define     PL_FT "./player_front.xpm"
#define     PL_LT "./player_left.xpm"
#define     PL_RT "./player_right.xpm"
#define     PL_BC "./player_back.xpm"
#define     GR "./game_ground.xpm"
#define     WIN_WEIGHT 1800
#define     WIN_HEIGHT 1200
#define     N 5


# ifndef ANIMATION_FRAMES
#  define ANIMATION_FRAMES 10
# endif

# include <stdio.h>
# include <stdlib.h>
# include "mlx/mlx.h"
# include <string.h>
# include <fcntl.h>
# include <unistd.h>

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
    char        *map;
}               t_data;


int     ft_close(int key, t_data *data);
int     key_event(int keycode, t_data *data);
int     mouse(int   button ,int  x, int y, t_data *data);
int	    ftcount(char const *s, char c);
char	**ft_split(char const *s, char c);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void    init_matrix(t_data *games);
void    map_exit_chack(int i, int j, t_data *games); 
void    ft_path_find(t_data *games);
int     ft_path(int y, int x, t_data *games);
void    ft_paht_put(t_data *games, int result);
void    ft_visited_clear(t_data *games);
int     ft_safe(int y, int j, t_data *games);


size_t	ft_strlcpy(char *restrict dst, const char *restrict src, size_t dstsize);
char	*ft_substr(char	const *s, unsigned int start, size_t len);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

size_t		ft_strlen(const char *str);
char	*ft_read(int fd);
char	*ft_strjoin(char const *s1, char const *s2);


#endif