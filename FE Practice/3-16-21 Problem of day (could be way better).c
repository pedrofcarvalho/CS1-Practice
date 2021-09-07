#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NO_SOLUTION 100000000

int minSteps(int x, int y);
int min (int x, int y);

int main()
{
  int x = 3;
  int y = 12;
  int steps;

  steps = minSteps(x, y);

  printf("Steps is: %d (should be 2)\n", steps);





  return 0;
}

int min(int x, int y)
{
  if (x < y) return x;
  return y;
}

int minSteps(int x, int y)
{
  int minCount;

  // base case
  if (x == y)
  {
    return 0;
  }

  // base case
  if (min(x, y) > y)
  {
    return NO_SOLUTION;
  }

  // if x is odd
  if (x % 2 == 1)
  {
    minCount = minSteps(x + 1, y) + 1;
    if (minCount == NO_SOLUTION)
    {
      return NO_SOLUTION;
    }
  }

  else if ((x * 2) < y)
  {
    minCount = minSteps(x * 2, y) + 1;
    if (minCount == NO_SOLUTION)
    {
      return NO_SOLUTION;
    }
  }

  if (x % 2 == 1)
  {
    minCount = minSteps(x + 1, y) + 1;
    if (minCount == NO_SOLUTION)
    {
      return NO_SOLUTION;
    }
  }

  return minCount;
}





















//
