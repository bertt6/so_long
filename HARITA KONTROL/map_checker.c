#include <unistd.h>
#include <string.h>

#define N 4

int ft_safe(int i, int j, int matrix[][N]) 
{
    (void)matrix[N][N];
    if (i >= 0 && i < N && j >= 0 && j < N)
         return(1);
    return(0);
}

// Bir kaynaktan (P) (değerine sahip bir hücre)
// bir hedefe (C/E) (toplanabilir(ler) değerine sahip bir hücreye 
// giden yol varsa 1 (Evet/True) değerini döndürür.
// Yol bulunamaz ise 0 (Hayır/False) döndürür.

int ft_path(int matrix[][N], int i, int j, int visited[][N])
{
    if(ft_safe(i, j, matrix) && matrix[i][j] != '1' && !visited[i][j])
    {
        visited[i][j] = 1;
        if(matrix[i][j] == 'C')
            return (1);
        if(ft_path(matrix, i - 1, j, visited))
            return (1);
        if(ft_path(matrix, i, j - 1, visited))
            return (1);
        if(ft_path(matrix, i + 1, j, visited))
            return (1);
        if(ft_path(matrix, i, j + 1, visited))
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

    memset(visited, 0, sizeof(visited));
    result = 0;
    i = -1;
    while(++i < N)
    {
        j = -1;
        while(++j < N)
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
    }
    if(result)
        write(1, "Evet/True\n", 11);
    else
        write(1, "Hayır/False\n", 12);
}

int main(void)
{
int matrix[N][N] = { { 'P', '1', '0', '0' }, 
                     { '1', '0', '1', '0' }, 
                     { '1', '0', '1', '0' },
                     { '1', 'C', '0', '0' } };

ft_path_find(matrix);
return (0); 
}
