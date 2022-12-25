int map_width(char *map[])
{
    int i;
    int j;

    j = 0;
    while(*map[j] != '\0')
    {
        i = 0;
        while(map[j][i])
            i++;
        j++;
    }
    return (j);
}
