
// Backtracking approach to a sudoku solver
// Input is a puzzle where the blanks are 0
// Output is the solution to the puzzle (hopefully one exists!!!)

#include <stdio.h>
#include <stdlib.h>

#define EMPTY 0
#define NOT_SOLVABLE 0
#define SOLVABLE 1
#define DIM 9

int dx[] = {0,0,0,1,1,1,2,2,2};
int dy[] = {0,1,2,0,1,2,0,1,2};
int start[] = {0,0,0,3,3,3,6,6,6};

// Return a 1 if the spot is okay
// Return a 0 if the spot is invalid
int isValid(int ** grid, int r, int c)
{
    // careful not to check empty spots
    if (grid[r][c] == EMPTY) // anti bugging
        return SOLVABLE;

    // check row
    for (int i = 0; i < DIM; i++)
        if (c != i && grid[r][c] == grid[r][i])
            return NOT_SOLVABLE;

    // check col
    for (int i = 0; i < DIM; i++)
        if (r != i && grid[r][c] == grid[i][c])
            return NOT_SOLVABLE;

    // check nonet (3x3 subgrid)
    for (int i = 0; i < DIM; i++)
    {
        int rr = start[r] + dy[i];
        int cc = start[c] + dx[i];
        if (rr == r && cc == c) continue; // avoid checking ourselves
        if (grid[r][c] == grid[rr][cc])
            return NOT_SOLVABLE;
    }

    return SOLVABLE;
}

// solver function (return a 1 if solved)
//                 (return a 0 if not solved)
// input (current grid, current row (0-8) and column (0-8) we are guessing)
// Recursive
int solveIt(int ** grid, int r, int c)
{
    if (c == DIM)
    {
      return solveIt(grid, r + 1, 0);
    }

    if (r == DIM) // finished
        return 1; // good

    // Check the situation
    // it's empty here
    if (grid[r][c] == EMPTY)
    {
        // there is no value here
        for (int i = 1; i <= DIM; i++)
        {
            grid[r][c] = i;
            if (isValid(grid, r, c)) // checking if this value is good
            {
                if (solveIt(grid, r, c + 1)) // if everything went fine, return 1
                {
                  return 1; // good
                }
            }
            grid[r][c] = EMPTY; // backtracking
        }
    }

    else
    {
        // there is a value here
        if (isValid(grid, r, c))
            return solveIt(grid, r, c + 1);
    }

    // We have not found a valid solution (will rarely hit here)
    return 0; // bad
}

void input(int ** grid)
{
    for (int i = 0; i < DIM; i++)
        for (int j = 0; j < DIM; j++)
        {
            int x;
            scanf("%d", &x);
            grid[i][j] = x;
        }
}

void output(int ** grid) {
    for (int i = 0; i < DIM; i++)
    {
        for (int j = 0; j < DIM; j++)
        {
          printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int ** grid;

    // Allocate the array of row pointers
    // Each row pointer will point to an array of ints which will represent
    // the row in question
    grid = calloc(DIM, sizeof(int *));

    // Allocate each row of the grid
    for (int i = 0; i < DIM; i++)
        grid[i] = calloc(DIM, sizeof(int));

    // Do the Sudoku puzzle
    input(grid);
    solveIt(grid, 0, 0);
    printf("\nOutput is:\n");
    output(grid);

    // Free the memory
    for (int i = 0; i < DIM; i++)
        free(grid[i]);
    free(grid);

    return 0;
}
