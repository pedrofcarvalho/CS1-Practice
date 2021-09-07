#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  int numCars, i;
  int * arriveTime = calloc(numCars, sizeof(int));
  int * eatTime = calloc(4 * numCars, sizeof(int));

  scanf("%d", &numCars);

  for (i = 0; i < numCars; ++i)
  {
    scanf("%d", &arriveTime[i]);
  }

  for (i = 0; i < 4 * numCars; ++i)
  {
    scanf("%d", &eatTime[i]);
  }







  return 0;
}
