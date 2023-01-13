#include "../so_long.h"

void line_control(t_data *data)
{
    int i = 0;
    int j = 0;
    int flag;

    while(data->map[0][j])
        j++;
    flag = j;
    while(data->map[i])
    {
        j = 0;  
        while(data->map[i][j])
            j++;
        if(j != flag)
        {
            printf("Harita uzunlugunda hata var!");
            exit(1);
        }
        i++;
    }
}

void collectable_control(t_data *data)
{
    int i = 0;
    int j = 0;
    
    i = 0;
    while(data->map[i])
    {
        j = 0;
        while(data->map[i][j])
        {
            if(data->map[i][j] == 'C' && data->controlmap[i][j] != '.')
            {
                printf("Ulaşılamayan coin var. KORDINATLARI : x = %d, y = %d", j, i);
                exit(1);
            }
            j++;
        }
        i++;
    }
}

void door_control(t_data *data)
{
    if(data->exit > 1)
    {
        printf("Birden fazla kapı bulunmaktadır!");
        exit(1);
    }
    printf("\n%d\n", data->exit);
}