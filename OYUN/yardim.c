#include "so_long.h"

int ft_safe(int y, int j, t_data *games) 
{
    if (y >= 0 && y < games->mat_y && j >= 0 && j < games->mat_x) 
        return (1);
    return (0); 
}

void init_matrix(t_data *games) {
    static int  exit_i;
    static int  exit_j;
    int         i;
    int         j;
    i = -1;
    while (games->matrix[++i]) 
    {
        j = -1;
        while (games->matrix[i][++j]) 
        {
            if (games->matrix[i][j] == 'E') 
            {
                exit_i = i;
                exit_j = j; games->matrix[i][j] = '1';
            }
            if (games->matrix[i][j] == 'C') 
            {
                games->matrix[i][j] = 'F'; 
                ft_path_find(games);
                games->matrix[i][j] = 'C'; 
            }
        }   
    }
    map_exit_chack(exit_i, exit_j, games); 
}

void ft_visited_clear(t_data *games) {
    int i; 
    int j;
    i = -1;
    while (++i <= games->mat_y) 
    {
        j = -1;
        while (++j <= games->mat_x) 
        {
            games->visited[i][j] = '0'; 
        }
    } 
}

int ft_path(int y, int x, t_data *games) 
{
    if (ft_safe(y, x, games) && games->matrix[y][x] != '1' && games->visited[y][x] != '1') 
    {
        games->visited[y][x] = '1';
        if (games->matrix[y][x] == 'F') 
            return (1);
        if (ft_path(y - 1, x, games)) 
            return (1);
        if (ft_path(y, x - 1, games)) 
            return (1);
        if (ft_path(y + 1, x, games))
            return (1);
        if (ft_path(y, x + 1, games)) 
        return (1);
    }
    return (0); 
}


void ft_paht_put(t_data *games, int result) 
{
    games = NULL;
    static int k;
    if (result) 
    {
        k++;
        printf("[%d] ", k);
        write(1, "KONTROL AŞAMALARI / CONTROL STAGES ... BAŞARILI SUCCESSFUL\n", 63); 
    }
    else
    {
        printf("[X] KONTROL AŞAMASI / CONTROL PHASE : BAŞARISIZ /UNSUCCESSFUL\nGeçersiz Harita: Tüm toplanabilir yada çıkışa erişim sağlanamıyor\nInvalid Map: All collectible or not accessible to exit");
    } 
}

void map_exit_chack(int i, int j, t_data *games) 
{
    games->matrix[i][j] = 'F';
    ft_path_find(games);
}


void ft_path_find(t_data *games) {
    int result;
    int i;
    int j;
    ft_visited_clear(games); 
    result = 0;
    i = -1;
    while (++i <= games->mat_y) 
    {
        j = -1;
        while (++j <= games->mat_x) 
        {
            if (games->matrix[i][j] == 'P' && games->visited[i][j] != '1') 
            {
                if (ft_path(i, j, games)) 
                {
                    result = 1;
                    break ; 
                }
            } 
        }
    }
    ft_paht_put(games, result); 
}