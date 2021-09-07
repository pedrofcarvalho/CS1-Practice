#include <stdio.h>
#include <stdlib.h>

// global constants
#define EMPTY 0
#define RED 2
#define BLACK 1
#define IMPOSSIBLE 0
#define POSSIBLE 1

// global indexes
int lastColIndex = 0, lastRowIndex = 0, firstColIndex = 0, firstRowIndex = 0;

// holds the black flower group sizes - relevant for isValid function
int ** blackRows;
int ** blackCols;

// holds the num of groups of black flowers - relevant for isValid function
int * rAmt;
int * cAmt;

// function prototypes
int ** createGrid(int rows, int columns);
int ** createRows(int rows);
int * createCols(int columns);
int solve(int ** grid, int currRow, int currCol, int numOfRows, int numOfCols);
int isValid(int ** grid, int r, int c, int rowSize, int colSize);
void printInput(int * rAmt, int * cAmt, int ** blackCols, int ** blackRows, int numOfCols, int numOfRows);
void printOutput(int ** grid, int numOfCols, int numOfRows);
int checkRow(int ** grid, int currRow, int currCol, int rowSize, int colSize);
int checkCol(int ** grid, int currRow, int currCol, int rowSize, int colSize);

int main()
{
  // variable declaration
  int numOfRows, numOfCols, i, j, numOfBlackCols;
  scanf("%d", &numOfRows);
  scanf("%d", &numOfCols);

  // allocates memory
  int ** grid = createGrid(numOfRows, numOfCols);

  rAmt = createCols(numOfRows);
  cAmt = createCols(numOfCols);

  blackRows = createRows(numOfRows);
  blackCols = createRows(numOfCols);

  // creating memory and inputting the row amount and black rows
  for (i = 0; i < numOfRows; ++i)
  {
    scanf("%d", &rAmt[i]);
    blackRows[i] = createCols(rAmt[i]);

    for (j = 0; j < rAmt[i]; j++)
    {
      scanf("%d", &blackRows[i][j]);
    }
  }

  // creating memory and inputting the columns amount and black columns
  for (i = 0; i < numOfCols; ++i)
  {
    scanf("%d", &cAmt[i]);
    blackCols[i] = createCols(cAmt[i]);

    for (j = 0; j < cAmt[i]; j++)
    {
      scanf("%d", &blackCols[i][j]);
    }
  }

  printInput(rAmt, cAmt, blackCols, blackRows, numOfCols, numOfRows); // debug
  solve(grid, 0, 0, numOfRows, numOfCols);
  printOutput(grid, numOfCols, numOfRows); // final answer (NEEDS TO TAKE OUT EXTRA OUTPUT LATER)

  return 0;
}

// prints input (debug)
void printInput(int * rAmt, int * cAmt, int ** blackCols, int ** blackRows, int numOfCols, int numOfRows)
{
  int i, j;

  printf("\nRows\n");
  for (i = 0; i < numOfRows; ++i)
  {
    printf("Index %d:\n", i);
    printf("cAmt = %d\n", rAmt[i]);
    printf("cBlack = ");

    for (j = 0; j < rAmt[i]; j++)
    {
      if (j == rAmt[i] - 1)
      {
        printf("%d\n\n", blackRows[i][j]);
        break;
      }

      printf("%d, ", blackRows[i][j]);
    }
  }


  printf("\nColumns\n");
  for (i = 0; i < numOfCols; ++i)
  {
    printf("Index %d:\n", i);
    printf("cAmt = %d\n", cAmt[i]);
    printf("cBlack = ");

    for (j = 0; j < cAmt[i]; j++)
    {
      if (j == cAmt[i] - 1)
      {
        printf("%d\n\n", blackCols[i][j]);
        break;
      }

      printf("%d, ", blackCols[i][j]);
    }
  }
}

// function prints the output
void printOutput(int ** grid, int numOfCols, int numOfRows)
{
  int i, j;
  // produces the output
  printf("This is the answer:\n"); // DELETE THIS LATER *************************************************
  // ^^^^ DELETE THIS LATER  *********************
  for (i = 0; i < numOfRows; i++)
  {
    for (j = 0; j < numOfCols; j++)
    {
      if (grid[i][j] == RED)
      {
        printf("%c", 'r');
      }

      else if (grid[i][j] == BLACK)
      {
        printf("%c", 'B');
      }

      else
      {
        printf("%d", grid[i][j]);
        // printf("BAD\n");
        // return;
      }

      if ((j + 1) != numOfCols)
      {
        printf(" ");
      }
    }
    printf("\n");
  }
}

// function creates grid
int ** createGrid(int numOfRows, int numOfCols)
{
  // allocates memory
  int ** ret = calloc(numOfRows, sizeof(int *));

  // allocates memory
  for (int i = 0; i < numOfRows; ++i)
  {
    ret[i] = calloc(numOfCols, sizeof(int));
  }

  return ret;
}

// creates the rows for a 2d array
int ** createRows(int numOfRows)
{
  int ** ret = calloc(numOfRows, sizeof(int *));

  return ret;
}

// creates the columns for a 2d array
int * createCols(int numOfCols)
{
  int * ret = calloc(numOfCols, sizeof(int));

  return ret;
}

int checkRow(int ** grid, int currRow, int currCol, int rowSize, int colSize)
{
  int rowGroup = 0, i, j = 0, x = 0, whileFlagIndex = -1, flag = 0;
  int * subRowGroup = calloc(20, sizeof(int));

  // row counter
  for (i = 0; i < rowSize; ++i)
  {
    if (flag == 1)
    {
      i = whileFlagIndex + 1;
    }

    x = i;
    flag = 0;

    if (grid[currRow][i] == BLACK)
    {
      rowGroup++;

      if (rowGroup > rAmt[i])
      {
        return IMPOSSIBLE;
      }
    }

    while (grid[currRow][x] == BLACK && (x != rowSize))
    {
      // // only triggers for first while loop iteration
      // if (x <= whileFlagIndex && flag == 0)
      // {
      //   break;
      // }

      flag = 1;
      whileFlagIndex = x;
      subRowGroup[j]++;
      x++;
    }

    if (subRowGroup[j] != blackRows[currRow][j] && flag == 1)
    {
      return IMPOSSIBLE;
    }

    if (flag)
    {
      ++j;
    }
  }

  return POSSIBLE;
}

int checkCol(int ** grid, int currRow, int currCol, int rowSize, int colSize)
{
  int colGroup = 0, i, j = 0, x = 0, whileFlagIndex = -1, flag = 0;
  int * subColGroup = calloc(20, sizeof(int));

  // col counter
  for (i = 0; i < colSize; ++i)
  {
    if (flag == 1)
    {
      i = whileFlagIndex + 1;
    }

    x = i;
    flag = 0;

    if (grid[i][currCol] == BLACK)// &&) // i > whileFlagIndex)
    {
      colGroup++;

      if (colGroup > cAmt[i])
      {
        return IMPOSSIBLE;
      }
    }

    while (grid[x][currCol] == BLACK && (x != colSize))
    {
      // // only triggers for first while loop iteration
      // if (x <= whileFlagIndex && flag == 0)
      // {
      //   break;
      // }

      flag = 1;
      whileFlagIndex = x;
      subColGroup[j]++;
      x++;
    }

    if (subColGroup[j] != blackCols[currCol][j] && flag == 1)
    {
      return IMPOSSIBLE;
    }

    if (flag)
    {
      ++j;
    }
  }

  return POSSIBLE;
}

// NEED TO CHANGE
int isValid(int ** grid, int currRow, int currCol, int rowSize, int colSize)
{
  if (checkRow(grid, currRow, currCol, rowSize, colSize) == IMPOSSIBLE)
  {
    return IMPOSSIBLE;
  }

  if (checkCol(grid, currRow, currCol, rowSize, colSize) == IMPOSSIBLE)
  {
    return IMPOSSIBLE;
  }

  // no rules went bad
  return POSSIBLE;
}

// solves the flower board - borrowed from binairo.c
int solve(int ** grid, int currRow, int currCol, int numOfRows, int numOfCols)
{
    if (currRow == numOfRows) // at bottom of grid
        return POSSIBLE;

    if (currCol == numOfCols) // at end of the row
    {
      return solve(grid, currRow + 1, 0, numOfRows, numOfCols);
    }

    // try black
    grid[currRow][currCol] = BLACK;
    if (isValid(grid, currRow, currCol, numOfRows, numOfCols) == POSSIBLE)
    {
      if (solve(grid, currRow, currCol + 1, numOfRows, numOfCols) == POSSIBLE)
      {
        return POSSIBLE;
      }
    }

    // try red
    grid[currRow][currCol] = RED;
    if (isValid(grid, currRow, currCol, numOfRows, numOfCols) == POSSIBLE)
    {
      if (solve(grid, currRow, currCol + 1, numOfRows, numOfCols) == POSSIBLE)
      {
        return POSSIBLE;
      }
    }

    // return fail
    grid[currRow][currCol] = EMPTY; // backtracking step
    return IMPOSSIBLE;
}
























//
