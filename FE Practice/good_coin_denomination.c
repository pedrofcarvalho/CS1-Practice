#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkCoin(int * arrayOfCoins, int arrSize);

int main()
{
      // max: 10, val of each se less then 1,000
  int coinAmounterPerSet, i, numOfSets, j, result;
  int * coinArray;

  scanf("%d", &numOfSets);

  for (i = 0; i < numOfSets; ++i)
  {
    scanf("%d", &coinAmounterPerSet);
    coinArray = calloc(coinAmounterPerSet, sizeof(int));

    for (j = 0; j < coinAmounterPerSet; ++j)
    {
      scanf("%d", &coinArray[j]);
    }
    result = checkCoin(coinArray, coinAmounterPerSet);
    printf("%d\n", result);

    free(coinArray);
  }

  return 0;
}

int checkCoin(int * arrayOfCoins, int arrSize)
{
  // 0 = good, 1 = bad
  int check = 0, i;

  for (i = 0; i < arrSize - 1; ++i)
  {
    if (arrayOfCoins[i + 1] < arrayOfCoins[i] * 2)
    {
      check = 1;
      return check;
    }
  }

  return check;
}
