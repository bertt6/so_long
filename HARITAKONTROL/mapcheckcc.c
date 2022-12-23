#include "kontrol.h"

void ft_argcheck(char *map[])
{
    int i;
    int j;

    j = 0;
    printf("CHECK : %s\n", map[4]);
    while(*map && map[j])
    {
        i = 0;
        while(map[j][i])
        {
            if(!((*map[i] == 'P' || *map[i] == '0' || *map[i] == '1' || *map[i] == '0' || *map[i] == 'E')))
            {    
                write(1, "Geçersiz Map!", 13);
                return ;
            }
            i++;
        }
        j++;
    }
    write(1, "Geçerli map!", 12);
}

int main()
{
    char **map;
    int fd = open("map.ber", O_RDWR);
    char *s = ft_read(fd);
    printf("%s", s);
    map = ft_split(s, '\n');
    ft_argcheck(map);
}
