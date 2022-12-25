#include "../so_long.h"

// int is_safe(int i, int j, char *map[])
// {
//     (void)map;
//     if (i >= 0 && i < games->mat_y && j >= 0 && j < games->mat_x) return (1);
//         return (0); 
// }
void ft_argcheck(char *map[])
{
    int i;
    int j;

    j = 0;
    while(*map && map[j])
    {
        i = 0;
        while(map[j][i])
        {
            if((map[j][i] != 'P') && (map[j][i] != '0') && (map[j][i] != '1') && (map[j][i] != 'E') && (map[j][i] != 'C') && (map[j][i] != '\n'))
            {    
                write(1, "Geçersiz Map!", 13);
                exit(1);
            }
            i++;
        }
        j++;
    }
    write(1, "Geçerli map!", 12);
}

int map_width(char *map[])
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(map[j][i])
        i++;
    return (i);
}

int map_height(char *map[])
{
    int i;
    int j;

    j = 0;
    i = 0;

        while(map[j])
            j++;

    return (j);
}

int find_player_x(char *map[])
{
    int i;
    int j;

    j = 0;
    i = 0;
    while(map[j][i])
    {
        i = 0;
        while(map[j][i])
        {
            if(map[j][i] == 'P')
                return(i);
            i++;
        }
        j++;
    }
    return 0;
}

int find_player_y(char *map[])
{
    int i;
    int j;

    j = 0;
    i = 0;
    while(map[j][i])
    {
        i = 0;
        while(map[j][i])
        {
            if(map[j][i] == 'P')
                return(j);
            i++;
        }
        j++;
    }
    return 0;
}
