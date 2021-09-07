#include <stdio.h>
#include <stdlib.h>

// N is the size of the 2D matrix   N*N
#define N 9

/* A utility function to print grid */
void print(int arr[N][N])
{
     for (int i = 0; i < N; i++)
      {
         for (int j = 0; j < N; j++)
            printf("%d ",arr[i][j]);
         printf("\n");
       }
}

int isValid(int grid[N][N], int row, int col, int num)
{

    for (int x = 0; x <= 8; x++)
    {
        if(grid[row][x] == num)
        {
            return 0;
        }
    }

    for (int x = 0; x <= 8; x++)
    {
        if (grid[x][col] == num)
        {
            return 0;
        }
    }

    int startRow = row - row % 3, startCol = col - col % 3;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid[i + startRow][j + startCol] == num)
            {
                return 0;
            }
        }
    }

    return 1;
}

int solve(int grid[N][N], int row, int col)
{

    if (row == N - 1 && col == N)
    {
        return 1;
    }

    if (col == N)
    {
        row++;
        col = 0;
    }


    if (grid[row][col] > 0)
    {
        return solve(grid, row, col + 1);
    }

    for (int num = 1; num <= N; num++)
    {

        if (isValid(grid, row, col, num)==1)
        {
            grid[row][col] = num;

            if (solve(grid, row, col + 1)==1)
            {
                return 1;
            }
        }
        grid[row][col] = 0;
    }
    return 0;
}

int main()
{
    // 0 means unassigned cells
    int grid[N][N] = { { 8, 5, 2, 0, 0, 0, 4, 0, 0 },
                       { 0, 6, 9, 0, 5, 8, 0, 1, 2 },
                       { 0, 3, 7, 0, 0, 9, 0, 0, 0 },
                       { 3, 0, 0, 6, 0, 0, 1, 0, 0 },
                       { 0, 8, 6, 5, 0, 1, 0, 7, 0 },
                       { 0, 0, 1, 2, 8, 4, 6, 0, 3 },
                       { 0, 0, 8, 0, 4, 0, 2, 6, 0 },
                       { 0, 1, 3, 9, 6, 2, 0, 4, 7 },
                       { 6, 0, 4, 8, 7, 0, 3, 9, 0 } };

    if (solve(grid, 0, 0)==1)
    {
        print(grid);
    }
    else
    {
        printf("No solution exists");
    }

    return 0;
}
