#include <unistd.h> 
#include <string.h>
#include "kontrol.h"

int ft_safe(int i, int j, int matrix[][N]) 
{
    (void) matrix[N][N];
    if (i >= 0 && i < N && j >= 0 && j < N)
        return (1);
    return (0);
}

int ft_path(int matrix[][N], int i, int j, int visited[][N])
{
    if (ft_safe(i, j, matrix) && matrix[i][j] != '1' && !visited[i][j]) 
    {
        visited[i][j] = 1;
        if (matrix[i][j] == 'C') 
            return (1);
        if (ft_path(matrix, i - 1, j, visited)) 
            return (1);
        if (ft_path(matrix, i, j - 1, visited)) 
            return (1);
        if (ft_path(matrix, i + 1, j, visited)) 
            return (1);
        if (ft_path(matrix, i, j + 1, visited)) 
            return (1);
    }
    return (0); 
}

void ft_path_find(int matrix[][N]) 
{    
    int visited[N][N];
    int result;
    int i;
    int j;

    memset(visited, 0 , sizeof(visited));
    result = 0;
    i = -1;
    while(++i < N)
    {
        if(matrix[i][j] == 'P' && !visited[i][j])
        {
            if(ft_path(matrix, i, j, visited))
            {
                result = 1;
                break;
            }
        }

    }
    if(result)
        write(1, "true\n", 5);
    else
        write(1, "false\n", 6);
}


int main(void)
{
    char **matrix;

    int fd = open("map.ber", O_RDWR);
    char *a = ft_read(fd);
    printf("%s\n", a);
    matrix = ft_split(a, '\n');
    return (0); 
}